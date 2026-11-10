#Requires -Version 5.1
<#
.SYNOPSIS
Build AquesTalk2 as a relocatable archive for a static wasm link.

.DESCRIPTION
PowerShell port of engines/aquestalk2/port/build-reloc.sh.

src/runtime.c is intentionally not compiled: the final module supplies
malloc/mem* through the link kit.  link/tools/reloc.ps1 compiles twice so the
engine's globals are namespaced before the archive is created.

.PARAMETER Out
Archive directory.  Defaults to $env:OUT or engines/aquestalk2/dist/reloc.

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

if (-not $Out) { $Out = Join-Path $Engine 'dist/reloc' }
if (-not [System.IO.Path]::IsPathRooted($Out)) { $Out = Join-Path $Here $Out }
if (-not $RelocTmp) { $RelocTmp = Join-Path $Here '.reloc-tmp' }
if (-not [System.IO.Path]::IsPathRooted($RelocTmp)) { $RelocTmp = Join-Path $Here $RelocTmp }

. (Join-Path $Root 'link/tools/reloc.ps1')
$Python = Resolve-Python -Explicit $Python
$Cc = Resolve-Compiler -Command $Cc
$LlvmAr = Resolve-RequiredTool -Name 'llvm-ar'

$cflags = @(
    '--target=wasm32', '-O2', '-nostdlib', '-ffreestanding', '-fno-builtin',
    '-fno-stack-protector', '-w',
    '-DAQ_FREESTANDING', '-DAQ_RELOC',
    '-Isrc',
    '-Wno-incompatible-pointer-types', '-Wno-int-conversion'
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
    $sources = Expand-RelocSources -Patterns @(
        'src/decomp.c'
        'src/image.c'
        'src/shim.c'
        'src/wasm_api.c'
    )

    Write-Host "AquesTalk2 -> $(Join-Path $Out 'libaq2.a')"
    Invoke-RelocArchive `
        -Manifest (Join-Path $Root 'link/abis/aq2.json') `
        -Archive (Join-Path $Out 'libaq2.a') `
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
