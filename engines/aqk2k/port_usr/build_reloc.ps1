#Requires -Version 5.1
<#
.SYNOPSIS
Build AqUsrDic (Check + memory-buffer Import/Export) as a relocatable archive.

.DESCRIPTION
PowerShell port of engines/aqk2k/port_usr/build_reloc.sh.

The generated runtime.c is not compiled; malloc/mem*/stdio come from the link
kit.  C and C++ (marisa-trie) translation units are both namespaced by
link/tools/reloc.ps1 before the archive is created.

.PARAMETER Out
Archive directory.  Defaults to $env:OUT or port_usr/build-wasm32/reloc.

.PARAMETER Cc
C compiler.  Defaults to $env:CC or clang.

.PARAMETER Cxx
C++ compiler.  Defaults to $env:CXX or clang++.
#>
[CmdletBinding(PositionalBinding = $false)]
param(
    [string]$Out = $env:OUT,
    [string]$RelocTmp = $env:RELOC_TMP,
    [string]$Cc = $(if ($env:CC) { $env:CC } else { 'clang' }),
    [string]$Cxx = $(if ($env:CXX) { $env:CXX } else { 'clang++' }),
    [string]$Python = $env:PYTHON
)
$ErrorActionPreference = 'Stop'

$Here = $PSScriptRoot
$Engine = Split-Path -Parent $Here
$Root = Split-Path -Parent (Split-Path -Parent $Engine)

if (-not $Out) { $Out = Join-Path $Here 'build-wasm32/reloc' }
if (-not [System.IO.Path]::IsPathRooted($Out)) { $Out = Join-Path $Here $Out }
if (-not $RelocTmp) { $RelocTmp = Join-Path $Here '.reloc-tmp' }
if (-not [System.IO.Path]::IsPathRooted($RelocTmp)) { $RelocTmp = Join-Path $Here $RelocTmp }

. (Join-Path $Root 'link/tools/reloc.ps1')
$Python = Resolve-Python -Explicit $Python
$Cc = Resolve-Compiler -Command $Cc
$Cxx = Resolve-Compiler -Command $Cxx
$LlvmAr = Resolve-RequiredTool -Name 'llvm-ar'

$resourceDir = Get-NativeOutput -FilePath $Cc -ArgumentList @('-print-resource-dir') |
    Select-Object -First 1
if (-not $resourceDir) {
    throw "'$Cc -print-resource-dir' produced no output"
}
$resourceDir = $resourceDir.Trim()

$cflags = @(
    '--target=wasm32-unknown-unknown', '-O2', '-nostdlib', '-w',
    '-fno-strict-aliasing', '-DAQK2K_WASM', '-DAQ_RELOC', '-Wno-everything',
    '-Ibuild-wasm32/gen'
)
$cxxflags = @(
    '--target=wasm32-unknown-unknown', '-std=c++17', '-O2', '-nostdlib', '-w',
    '-fno-exceptions', '-fno-rtti', '-Wno-everything',
    '-nostdinc', '-isystem', (Join-Path $resourceDir 'include'),
    '-Ibuild-wasm32/gen',
    '-Imarisa_fs/cxx', '-Imarisa_fs/include', '-Imarisa_fs/lib'
)

$compileOne = {
    param($Src, $Obj, $Pass, $IncludeHeader)

    if ($Src -like '*.cc') {
        $arguments = @($cxxflags)
    }
    else {
        $arguments = @($cflags)
    }
    if ($Pass -eq 2) {
        $arguments += @('-include', $IncludeHeader)
    }
    $arguments += @('-c', $Src, '-o', $Obj)

    if ($Src -like '*.cc') {
        Invoke-Native -FilePath $Cxx -ArgumentList $arguments
    }
    else {
        Invoke-Native -FilePath $Cc -ArgumentList $arguments
    }
}

Push-Location -LiteralPath $Here
try {
    Invoke-Native -FilePath $Python -ArgumentList @('tools/gen_image.py')
    Invoke-Native -FilePath $Python -ArgumentList @('tools/gen_check.py')
    Invoke-Native -FilePath $Python -ArgumentList @('tools/gen_wasm32.py')

    $sources = Expand-RelocSources -Patterns @(
        'build-wasm32/gen/shim.c'
        'build-wasm32/gen/image.c'
        'build-wasm32/gen/decomp_check.c'
        'build-wasm32/gen/api_check.c'
        'build-wasm32/gen/errors.c'
        'src/api_usr.c'
        'src/marisa_glue.cc'
        'marisa_fs/cxx_runtime.cc'
        'marisa_fs/lib/marisa/agent.cc'
        'marisa_fs/lib/marisa/keyset.cc'
        'marisa_fs/lib/marisa/trie.cc'
        'marisa_fs/lib/marisa/grimoire/trie/louds-trie.cc'
        'marisa_fs/lib/marisa/grimoire/trie/tail.cc'
        'marisa_fs/lib/marisa/grimoire/vector/bit-vector.cc'
        'marisa_fs/lib/marisa/grimoire/io/io_mem.cc'
    )

    Write-Host "AqUsrDic -> $(Join-Path $Out 'libaqusr.a')"
    Invoke-RelocArchive `
        -Manifest (Join-Path $Root 'link/abis/aqusr.json') `
        -Archive (Join-Path $Out 'libaqusr.a') `
        -Root $Root `
        -Tmp $RelocTmp `
        -Sources $sources `
        -CompileOne $compileOne `
        -Python $Python `
        -LlvmAr $LlvmAr
}
finally {
    Pop-Location
}
Remove-Item -LiteralPath $RelocTmp -Recurse -Force -ErrorAction SilentlyContinue
