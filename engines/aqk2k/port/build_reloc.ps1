#Requires -Version 5.1
<#
.SYNOPSIS
Build AqKanji2Koe as a relocatable archive for a static wasm link.

.DESCRIPTION
PowerShell port of engines/aqk2k/port/build_reloc.sh.

The generated runtime.c (freestanding allocator, mem*, stdio stubs) is not
compiled; the final module supplies those through the link kit.  The
decompiled sources are regenerated with tools/gen_wasm32.py first, then
link/tools/reloc.ps1 compiles twice to namespace every global.

.PARAMETER Out
Archive directory.  Defaults to $env:OUT or port/build-wasm32/reloc.

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
$Engine = Split-Path -Parent $Here
$Root = Split-Path -Parent (Split-Path -Parent $Engine)

if (-not $Out) { $Out = Join-Path $Here 'build-wasm32/reloc' }
if (-not [System.IO.Path]::IsPathRooted($Out)) { $Out = Join-Path $Here $Out }
if (-not $RelocTmp) { $RelocTmp = Join-Path $Here '.reloc-tmp' }
if (-not [System.IO.Path]::IsPathRooted($RelocTmp)) { $RelocTmp = Join-Path $Here $RelocTmp }

. (Join-Path $Root 'link/tools/reloc.ps1')
$Python = Resolve-Python -Explicit $Python
$Cc = Resolve-Compiler -Command $Cc
$LlvmAr = Resolve-RequiredTool -Name 'llvm-ar'

$cflags = @(
    '--target=wasm32-unknown-unknown', '-O2', '-nostdlib', '-w',
    '-fno-strict-aliasing', '-DAQK2K_WASM',
    '-Wno-incompatible-pointer-types', '-Wno-pointer-sign', '-Wno-int-conversion',
    '-Wno-implicit-function-declaration', '-Wno-shift-op-parentheses',
    '-Wno-return-mismatch', '-Wno-unused-value',
    '-Ibuild-wasm32/gen'
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

Push-Location -LiteralPath $Here
try {
    Invoke-Native -FilePath $Python -ArgumentList @('tools/gen_wasm32.py')

    $sources = Expand-RelocSources -Patterns @(
        'build-wasm32/gen/shim.c'
        'build-wasm32/gen/image.c'
        'build-wasm32/gen/cold_stubs.c'
        'build-wasm32/gen/decomp.c'
        'build-wasm32/gen/api_raw.c'
        'build-wasm32/gen/lookup_c.c'
    )

    Write-Host "AqKanji2Koe -> $(Join-Path $Out 'libaqk2k.a')"
    Invoke-RelocArchive `
        -Manifest (Join-Path $Root 'link/abis/aqk2k.json') `
        -Archive (Join-Path $Out 'libaqk2k.a') `
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
