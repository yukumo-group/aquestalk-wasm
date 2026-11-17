#Requires -Version 5.1
<#
.SYNOPSIS
Link every engine into one single-memory WebAssembly module with Rust code.

.DESCRIPTION
PowerShell port of scripts/build-reloc.sh.

    ./scripts/build-reloc.ps1              build + parity test
    ./scripts/build-reloc.ps1 -NoTest      build only

For each engine this runs engines/<...>/build-reloc.ps1, which compiles a
namespaced static archive (see link/tools/gen_prefix.py).  The archives are
then linked with:

  * link/host/aq_host.c   -- string/stdio/time/trap helpers (C)
  * link/host/Cargo.toml  -- malloc/free/calloc/realloc on Rust's allocator

The result has no imports, one memory and one table, so it runs in browsers
that do not implement the multi-memory proposal.

.PARAMETER NoTest
Skip the node link/test/reloc.mjs parity run.

.PARAMETER Help
Show usage and exit.

.PARAMETER Out
Output directory.  Defaults to $env:OUT or dist/reloc.

.PARAMETER Bundle
Output module.  Defaults to $env:BUNDLE or dist/aquestalk.wasm.

.PARAMETER Cc
C compiler.  Defaults to $env:CC or clang.  wasm-ld, llvm-ar and llvm-nm are
looked up on PATH and next to this compiler.

.PARAMETER Python
Python 3 interpreter.  Defaults to $env:PYTHON, then python/python3.

.PARAMETER InitialMemory
Initial linear memory in bytes.  Defaults to $env:INITIAL_MEMORY or 64 MiB.

.PARAMETER MaxMemory
Maximum linear memory in bytes.  Defaults to $env:MAX_MEMORY or 1 GiB.

.PARAMETER StackSize
Stack size in bytes.  Defaults to $env:STACK_SIZE or 16 MiB.

.EXAMPLE
./scripts/build-reloc.ps1

.EXAMPLE
./scripts/build-reloc.ps1 -NoTest -Out dist/reloc
#>
[CmdletBinding(PositionalBinding = $false)]
param(
    [Alias('h')][switch]$Help,
    [Alias('no-test')][switch]$NoTest,
    [string]$Out = $env:OUT,
    [string]$Bundle = $env:BUNDLE,
    [string]$Cc = $(if ($env:CC) { $env:CC } else { 'clang' }),
    [string]$Python = $env:PYTHON,
    [long]$InitialMemory = $(if ($env:INITIAL_MEMORY) { [long]$env:INITIAL_MEMORY } else { 67108864 }),
    [long]$MaxMemory = $(if ($env:MAX_MEMORY) { [long]$env:MAX_MEMORY } else { 1073741824 }),
    [long]$StackSize = $(if ($env:STACK_SIZE) { [long]$env:STACK_SIZE } else { 16777216 }),
    [Parameter(ValueFromRemainingArguments = $true)][string[]]$Rest = @()
)
$ErrorActionPreference = 'Stop'

function Show-Usage {
    Write-Host @'
Usage: ./scripts/build-reloc.ps1 [-NoTest] [-Out DIR] [-Bundle FILE]
                                 [-Cc CC] [-Python PYTHON]
                                 [-InitialMemory N] [-MaxMemory N] [-StackSize N]

  -NoTest        build only (same as --no-test)
  -h, --help     show this help
'@
}

if ($Help) {
    Show-Usage
    exit 0
}

foreach ($argument in $Rest) {
    if ($argument -eq '--no-test' -or $argument -eq '-no-test') {
        $NoTest = $true
    }
    elseif ($argument -eq '-h' -or $argument -eq '--help' -or $argument -eq '-?') {
        Show-Usage
        exit 0
    }
    else {
        [Console]::Error.WriteLine("unknown argument: $argument")
        exit 2
    }
}

$Root = Split-Path -Parent $PSScriptRoot
. (Join-Path $Root 'link/tools/reloc.ps1')

if (-not $Out) { $Out = Join-Path $Root 'dist/reloc' }
if (-not $Bundle) { $Bundle = Join-Path $Root 'dist/aquestalk.wasm' }
if (-not [System.IO.Path]::IsPathRooted($Out)) { $Out = Join-Path $Root $Out }
if (-not [System.IO.Path]::IsPathRooted($Bundle)) { $Bundle = Join-Path $Root $Bundle }

$Python = Resolve-Python -Explicit $Python
$Cc = Resolve-Compiler -Command $Cc
$LlvmAr = Resolve-RequiredTool -Name 'llvm-ar'
$WasmLd = Resolve-RequiredTool -Name 'wasm-ld'
$null = Resolve-RequiredTool -Name 'llvm-nm'
$Cargo = Resolve-RequiredTool -Name 'cargo'

New-Item -ItemType Directory -Force -Path $Out, (Split-Path -Parent $Bundle) | Out-Null

Write-Host '== relocatable engine archives'
$engineBuilds = @(
    'engines/aquestalk1/recovered/wasm/build-reloc.ps1'
    'engines/aquestalk2/port/build-reloc.ps1'
    'engines/aquestalk10/port/build-reloc.ps1'
    'engines/aqk2k/port/build_reloc.ps1'
    'engines/aqk2k/port_usr/build_reloc.ps1'
)
foreach ($relative in $engineBuilds) {
    $scriptPath = Join-Path $Root $relative
    if (-not (Test-Path -LiteralPath $scriptPath -PathType Leaf)) {
        throw "missing $relative"
    }
    & $scriptPath -Out $Out -Cc $Cc -Python $Python
}

Write-Host '== link kit host'
$hostObject = Join-Path $Out 'aq_host.o'
$hostArchive = Join-Path $Out 'libaqhost.a'
Invoke-Native -FilePath $Cc -ArgumentList @(
    '--target=wasm32', '-O2', '-nostdlib', '-ffreestanding', '-fno-builtin',
    '-fno-stack-protector', '-w', '-c',
    (Join-Path $Root 'link/host/aq_host.c'), '-o', $hostObject
)
Invoke-Native -FilePath $LlvmAr -ArgumentList @('crs', $hostArchive, $hostObject)
Invoke-Native -FilePath $Cargo -ArgumentList @(
    'build', '--manifest-path', (Join-Path $Root 'link/host/Cargo.toml'),
    '--target', 'wasm32-unknown-unknown', '--release'
)
$hostRustArchive = Join-Path $Root 'link/host/target/wasm32-unknown-unknown/release/libaq_host.a'
if (-not (Test-Path -LiteralPath $hostRustArchive -PathType Leaf)) {
    throw "cargo did not produce $hostRustArchive"
}

Write-Host '== wasm-ld'
$exportsText = Join-Path $Out 'exports.txt'
$exportsArguments = Join-Path $Out 'exports.args'
$exportLines = @(& $Python (Join-Path $Root 'link/tools/exports.py') --write $exportsText)
if ($LASTEXITCODE -ne 0) {
    throw "'exports.py' exited with code $LASTEXITCODE"
}
Set-Content -LiteralPath $exportsArguments -Value $exportLines -Encoding Ascii

$linkArguments = @('--no-entry', '--export-memory') + $exportLines + @(
    "--initial-memory=$InitialMemory",
    "--max-memory=$MaxMemory",
    '-z', "stack-size=$StackSize",
    '-o', $Bundle,
    $hostObject,
    '--whole-archive',
    (Join-Path $Out 'libaq1.a'),
    (Join-Path $Out 'libaq2.a'),
    (Join-Path $Out 'libaq10.a'),
    (Join-Path $Out 'libaqk2k.a'),
    (Join-Path $Out 'libaqusr.a'),
    '--no-whole-archive',
    $hostRustArchive
)
Invoke-Native -FilePath $WasmLd -ArgumentList $linkArguments

$buildInfo = @'
import json, sys
from pathlib import Path
root, bundle, out = map(Path, sys.argv[1:4])
initial, maximum, stack = map(int, sys.argv[4:7])
info = {
    "bundle": bundle.relative_to(root).as_posix(),
    "bytes": bundle.stat().st_size,
    "imports": [],
    "memory": {"count": 1, "initial": initial, "max": maximum},
    "stack": stack,
    "archives": sorted(p.name for p in out.glob("lib*.a")),
}
(out / "build-info.json").write_text(json.dumps(info, indent=2) + "\n")
'@
$buildInfo | & $Python - $Root $Bundle $Out $InitialMemory $MaxMemory $StackSize
if ($LASTEXITCODE -ne 0) {
    throw 'build-info generation failed'
}

$display = $Bundle
if ($display.StartsWith($Root, [System.StringComparison]::OrdinalIgnoreCase)) {
    $display = $display.Substring($Root.Length).TrimStart('\', '/')
}
$display = $display -replace '\\', '/'
Write-Host ('  {0,-24} {1}' -f $display, (Format-FileSize (Get-Item -LiteralPath $Bundle).Length))
Write-Host "wrote $exportsText"

if (-not $NoTest) {
    $node = Resolve-RequiredTool -Name 'node'
    Invoke-Native -FilePath $node -ArgumentList @((Join-Path $Root 'link/test/reloc.mjs'))
}
