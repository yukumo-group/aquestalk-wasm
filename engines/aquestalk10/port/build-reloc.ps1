#Requires -Version 5.1
<#
.SYNOPSIS
Build AquesTalk10 as a relocatable archive for a static wasm link.

.DESCRIPTION
PowerShell port of engines/aquestalk10/port/build-reloc.sh.

port/src/minic.c (freestanding allocator + mem*) is not compiled; the final
module supplies those through the link kit.  link/tools/reloc.ps1 compiles
twice so the decompiled globals are namespaced.

.PARAMETER Out
Archive directory.  Defaults to $env:OUT or engines/aquestalk10/port/web/reloc.

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

if (-not $Out) { $Out = Join-Path $Engine 'port/web/reloc' }
if (-not [System.IO.Path]::IsPathRooted($Out)) { $Out = Join-Path $Engine $Out }
if (-not $RelocTmp) { $RelocTmp = Join-Path $Here '.reloc-tmp' }
if (-not [System.IO.Path]::IsPathRooted($RelocTmp)) { $RelocTmp = Join-Path $Engine $RelocTmp }

. (Join-Path $Root 'link/tools/reloc.ps1')
$Python = Resolve-Python -Explicit $Python
$Cc = Resolve-Compiler -Command $Cc
$LlvmAr = Resolve-RequiredTool -Name 'llvm-ar'

$cflags = @(
    '--target=wasm32', '-std=gnu11', '-O2', '-nostdlib', '-ffreestanding',
    '-fno-builtin', '-fno-strict-aliasing', '-fwrapv',
    '-fno-stack-protector', '-w', '-Wno-everything',
    '-DAQTK_FREESTANDING', '-DAQ_RELOC',
    '-Iport/src'
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
    # image.c is generated from the original .so and is not in git.
    if (-not (Test-Path -LiteralPath 'port/src/image.c' -PathType Leaf)) {
        Invoke-Native -FilePath $Python -ArgumentList @('port/tools/gen_image.py')
    }

    $sources = Expand-RelocSources -Patterns @(
        'port/src/wasm_api.c'
        'port/src/decomp.c'
        'port/src/image.c'
    )

    Write-Host "AquesTalk10 -> $(Join-Path $Out 'libaq10.a')"
    Invoke-RelocArchive `
        -Manifest (Join-Path $Root 'link/abis/aq10.json') `
        -Archive (Join-Path $Out 'libaq10.a') `
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
