# Shared driver for the relocatable engine builds (PowerShell port of reloc.sh).
#
# Each engine's build-reloc.ps1 sets:
#   $Root        repository root
#   $RelocTmp    scratch directory (one per engine)
#   $Sources     array of source files
#   $CompileOne  script block (src, out, pass, includeHeader) that compiles one
#                translation unit; includeHeader is $null on pass 1
#
# and then calls:
#   Invoke-RelocArchive -Manifest <manifest.json> -Archive <out\libname.a> ...
#
# Pass 1 collects the engine's globals, gen_prefix.py writes a header, and
# pass 2 recompiles with it so the archive is namespaced.

# Run a native executable and fail the build when it returns a non-zero exit
# code.  Windows PowerShell 5.1 does not turn native failures into terminating
# errors on its own.
function Invoke-Native {
    [CmdletBinding()]
    param(
        [Parameter(Mandatory = $true)][string]$FilePath,
        [string[]]$ArgumentList = @()
    )

    # Windows PowerShell 5.1 turns native stderr into a terminating error when
    # the caller pipelines or redirects output while $ErrorActionPreference is
    # Stop (cargo prints its progress on stderr).  Keep native stderr
    # non-terminating here; the exit code below is the authority.
    $ErrorActionPreference = 'Continue'
    Write-Verbose ("run: {0} {1}" -f $FilePath, ($ArgumentList -join ' '))
    & $FilePath @ArgumentList
    $exitCode = $LASTEXITCODE
    if ($null -ne $exitCode -and $exitCode -ne 0) {
        throw "'$FilePath' exited with code $exitCode"
    }
}

# Run a native executable and return its stdout lines.
function Get-NativeOutput {
    [CmdletBinding()]
    param(
        [Parameter(Mandatory = $true)][string]$FilePath,
        [string[]]$ArgumentList = @()
    )

    # See Invoke-Native: native stderr must not become a terminating error.
    $ErrorActionPreference = 'Continue'
    Write-Verbose ("run: {0} {1}" -f $FilePath, ($ArgumentList -join ' '))
    $output = & $FilePath @ArgumentList
    $exitCode = $LASTEXITCODE
    if ($null -ne $exitCode -and $exitCode -ne 0) {
        throw "'$FilePath' exited with code $exitCode"
    }
    return @($output)
}

# Resolve a tool to a full path.  Explicit paths win, then PATH, then a known
# toolchain directory (usually the one that holds clang.exe).
function Get-ToolPath {
    [CmdletBinding()]
    param(
        [Parameter(Mandatory = $true)][string]$Name,
        [string]$PreferDirectory
    )

    if (Test-Path -LiteralPath $Name -PathType Leaf) {
        return (Resolve-Path -LiteralPath $Name).ProviderPath
    }

    $command = Get-Command -Name $Name -CommandType Application -ErrorAction SilentlyContinue |
        Select-Object -First 1
    if ($command) {
        return $command.Source
    }

    if ($PreferDirectory) {
        foreach ($extension in @('.exe', '.cmd', '.bat', '')) {
            $candidate = Join-Path $PreferDirectory ($Name + $extension)
            if (Test-Path -LiteralPath $candidate -PathType Leaf) {
                return (Resolve-Path -LiteralPath $candidate).ProviderPath
            }
        }
    }
    return $null
}

# Put a toolchain directory on PATH so tools that re-exec by name
# (gen_prefix.py runs llvm-nm) can find their siblings.
function Add-ToolDirectory {
    [CmdletBinding()]
    param([string]$Directory)

    if (-not $Directory) {
        return
    }
    $full = [System.IO.Path]::GetFullPath($Directory)
    $entries = @($env:PATH -split ';' | Where-Object { $_ })
    if ($entries -notcontains $full) {
        $env:PATH = $full + ';' + $env:PATH
    }
}

# Resolve a compiler and make its LLVM siblings reachable by name.
function Resolve-Compiler {
    [CmdletBinding()]
    param([Parameter(Mandatory = $true)][string]$Command)

    $path = Get-ToolPath -Name $Command
    if (-not $path) {
        throw "missing $Command"
    }
    $directory = Split-Path -Parent $path
    if ($directory) {
        Add-ToolDirectory -Directory $directory
    }
    return $path
}

function Resolve-RequiredTool {
    [CmdletBinding()]
    param([Parameter(Mandatory = $true)][string]$Name)

    $path = Get-ToolPath -Name $Name
    if (-not $path) {
        throw "missing $Name"
    }
    return $path
}

# Find a usable Python 3.  On Windows `python` is tried before `python3`: the
# latter is often the Microsoft Store app-execution alias, which exists but
# only prints an error.
function Resolve-Python {
    [CmdletBinding()]
    param([string]$Explicit)

    $candidates = @()
    if ($Explicit) {
        $candidates = @($Explicit)
    }
    elseif ($env:PYTHON) {
        $candidates = @($env:PYTHON)
    }
    elseif ($env:OS -eq 'Windows_NT') {
        $candidates = @('python', 'python3')
    }
    else {
        $candidates = @('python3', 'python')
    }

    foreach ($name in $candidates) {
        $path = Get-ToolPath -Name $name
        if (-not $path) {
            continue
        }
        if ($path -like '*\Microsoft\WindowsApps\python*.exe') {
            continue
        }
        # The generators open the UTF-8 engine sources without an explicit
        # encoding.  Without UTF-8 mode Windows Python uses the ANSI code page
        # and fails on Japanese text.  Linux builds are UTF-8 already.
        $env:PYTHONUTF8 = '1'
        return $path
    }
    throw "missing python (install Python 3 or pass -Python <path>)"
}

# Expand a bash-style source list: wildcards become sorted file lists
# (like `shopt -s nullglob`), plain entries are kept as written.
function Expand-RelocSources {
    [CmdletBinding()]
    param([Parameter(Mandatory = $true)][string[]]$Patterns)

    $sources = New-Object System.Collections.Generic.List[string]
    foreach ($pattern in $Patterns) {
        if ($pattern -match '[*?\[]') {
            $matches = @(Get-ChildItem -Path $pattern -File -ErrorAction SilentlyContinue |
                Sort-Object Name)
            foreach ($file in $matches) {
                $sources.Add($file.FullName)
            }
        }
        else {
            $sources.Add($pattern)
        }
    }
    if ($sources.Count -eq 0) {
        throw 'no sources'
    }
    return $sources.ToArray()
}

# Human-readable size, matching the `du -h` column of the shell build.
function Format-FileSize {
    param([long]$Bytes)

    $invariant = [System.Globalization.CultureInfo]::InvariantCulture
    if ($Bytes -ge 1GB) {
        return [string]::Format($invariant, '{0:0.0}G', $Bytes / 1GB)
    }
    if ($Bytes -ge 1MB) {
        return [string]::Format($invariant, '{0:0.0}M', $Bytes / 1MB)
    }
    if ($Bytes -ge 1KB) {
        return [string]::Format($invariant, '{0:0.0}K', $Bytes / 1KB)
    }
    return [string]::Format($invariant, '{0}', $Bytes)
}

function Invoke-RelocArchive {
    [CmdletBinding()]
    param(
        [Parameter(Mandatory = $true)][string]$Manifest,
        [Parameter(Mandatory = $true)][string]$Archive,
        [Parameter(Mandatory = $true)][string]$Root,
        [Parameter(Mandatory = $true)][string]$Tmp,
        [Parameter(Mandatory = $true)][string[]]$Sources,
        [Parameter(Mandatory = $true)][scriptblock]$CompileOne,
        [Parameter(Mandatory = $true)][string]$Python,
        [Parameter(Mandatory = $true)][string]$LlvmAr
    )

    $pass1Dir = Join-Path $Tmp 'pass1'
    $pass2Dir = Join-Path $Tmp 'pass2'
    $archiveDir = Split-Path -Parent $Archive
    $directories = @($pass1Dir, $pass2Dir)
    if ($archiveDir) {
        $directories += $archiveDir
    }
    New-Item -ItemType Directory -Force -Path $directories | Out-Null

    $objects1 = New-Object System.Collections.Generic.List[string]
    for ($index = 0; $index -lt $Sources.Count; $index++) {
        $object = Join-Path $pass1Dir ('{0:000}_{1}.o' -f $index, [System.IO.Path]::GetFileName($Sources[$index]))
        & $CompileOne $Sources[$index] $object 1 $null
        $objects1.Add($object)
    }

    $header = Join-Path $Tmp 'prefix.h'
    $report = Join-Path $Tmp 'prefix.json'
    $prefixArguments = @(
        (Join-Path $Root 'link/tools/gen_prefix.py'),
        '--manifest', $Manifest,
        '--objects'
    ) + $objects1.ToArray() + @('--header', $header, '--report', $report)
    Invoke-Native -FilePath $Python -ArgumentList $prefixArguments

    $objects2 = New-Object System.Collections.Generic.List[string]
    for ($index = 0; $index -lt $Sources.Count; $index++) {
        $object = Join-Path $pass2Dir ('{0:000}_{1}.o' -f $index, [System.IO.Path]::GetFileName($Sources[$index]))
        & $CompileOne $Sources[$index] $object 2 $header
        $objects2.Add($object)
    }

    if (Test-Path -LiteralPath $Archive) {
        Remove-Item -LiteralPath $Archive -Force
    }
    Invoke-Native -FilePath $LlvmAr -ArgumentList (@('crs', $Archive) + $objects2.ToArray())

    $symbols = [System.IO.Path]::ChangeExtension($Archive, '.symbols.json')
    Copy-Item -LiteralPath $report -Destination $symbols -Force
    Write-Host ('  {0,-28} {1}' -f [System.IO.Path]::GetFileName($Archive),
        (Format-FileSize (Get-Item -LiteralPath $Archive).Length))
}
