#Requires -Version 5.1
<#
.SYNOPSIS
Build AquesTalk1 as a relocatable archive for a static wasm link.

.DESCRIPTION
PowerShell port of engines/aquestalk1/recovered/wasm/build-reloc.sh.

The module keeps the engine sources but drops recovered/wasm/runtime.c: the
final module uses the embedder's allocator and libc.  link/tools/reloc.ps1
compiles twice so every global can be namespaced (see gen_prefix.py).

.PARAMETER Out
Archive directory.  Defaults to $env:OUT or engines/aquestalk1/dist/reloc.

.PARAMETER Cc
C compiler.  Defaults to $env:CC or clang.
#>
[CmdletBinding(PositionalBinding = $false)]
param(
    [string]$Out = $env:OUT,
    [string]$RelocTmp = $env:RELOC_TMP,
    [string]$Cc = $(if ($env:CC) { $env:CC } else { 'clang' }),
    [string]$Python = $env:PYTHON
)
$ErrorActionPreference = 'Stop'

$Here = $PSScriptRoot
$Engine = Split-Path -Parent (Split-Path -Parent $Here)
$Root = Split-Path -Parent (Split-Path -Parent $Engine)

if (-not $Out) { $Out = Join-Path $Engine 'dist/reloc' }
if (-not [System.IO.Path]::IsPathRooted($Out)) { $Out = Join-Path $Engine $Out }
if (-not $RelocTmp) { $RelocTmp = Join-Path $Here '.reloc-tmp' }
if (-not [System.IO.Path]::IsPathRooted($RelocTmp)) { $RelocTmp = Join-Path $Engine $RelocTmp }

. (Join-Path $Root 'link/tools/reloc.ps1')
$Python = Resolve-Python -Explicit $Python
$Cc = Resolve-Compiler -Command $Cc
$LlvmAr = Resolve-RequiredTool -Name 'llvm-ar'

$cflags = @(
    '--target=wasm32', '-O2', '-nostdlib', '-ffreestanding', '-fno-builtin',
    '-fno-stack-protector', '-w',
    '-D__stdcall=', '-DAQ_FREESTANDING', '-DAQ_RELOC',
    '-fpermissive', '-Wno-int-conversion', '-Wno-incompatible-pointer-types',
    '-Irecovered/include', '-Irecovered/f3port/include',
    '-Irecovered/wasm/freestanding'
)

$compileOne = {
    param($Src, $Obj, $Pass, $IncludeHeader)

    $arguments = @($cflags)
    if ($Pass -eq 2) {
        $arguments += @('-include', $IncludeHeader)
    }
    $arguments += @('-c', $Src, '-o', $Obj)
    Invoke-Native -FilePath $Cc -ArgumentList $arguments
}

Push-Location -LiteralPath $Engine
try {
    $sources = Expand-RelocSources -Patterns @(
        'recovered/src/api/ot_api.c'
        'recovered/src/text/*.c'
        'recovered/src/audio/*.c'
        'recovered/src/synth/*.c'
        'recovered/src/data/*.c'
        'recovered/src/f3/*.c'
        'recovered/f3port/src/*.c'
        'recovered/wasm/wasm_api.c'
    )

    Write-Host "AquesTalk1 -> $(Join-Path $Out 'libaq1.a')"
    Invoke-RelocArchive `
        -Manifest (Join-Path $Root 'link/abis/aq1.json') `
        -Archive (Join-Path $Out 'libaq1.a') `
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
