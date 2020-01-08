#########################################################
#                                                       #
#     Copyright (C) Microsoft. All rights reserved.     #
#                                                       #
#########################################################

#------------------------------------------------------------------------------

param (
    [string]$spectreRoot    = $(throw "-spectreRoot is required."),
    [string]$projectName    = $(throw "-projectName is required."),
    [string]$compiler       = $(throw "-compiler is required."),
    [string]$platform       = $(throw "-platform is required."),
    [string]$configuration  = $(throw "-configuration is required."),
    [string]$projectsToCopy = $(throw "-projectsToCopy is required"),
    [switch]$deployToAppX   = $false
)

#------------------------------------------------------------------------------

$scriptDirectory = Split-Path $MyInvocation.MyCommand.Path
. (Join-Path $scriptDirectory Common.ps1)

#------------------------------------------------------------------------------

Write-Output "Copying dependencies for '$projectName'."

$thisProjectOutDir = [string]"$spectreRoot\Built\Out\$compiler\$platform\$configuration\$projectName\"
if ((Test-Path $thisProjectOutDir) -eq $false)
{
    FatalError "Unable to locate '$thisProjectOutDir'."
}

$projectsToCopy.Split(";") | ForEach {
    $item = $_.Trim()

    if ($item -eq [string]"")
    {
        continue
    }

    # We default to the current compiler version of the project
    $itemCompiler = $compiler
    $itemProject  = $item

    $regexSpecificVersion = "\[(?<version>.*)\](?<project>.*)"
    $res = $item -match $regexSpecificVersion
    if ($res -eq $true)
    {
        $itemCompiler = $matches['version']
        $itemProject  = $matches['project']
    }

    # If there is no version specified for the dependency, we use the current compiler version
    if ($itemCompiler -eq [string]"")
    {
        $itemCompiler = $compiler
    }

    $directoryToCopy = [string]"$spectreRoot\Built\Out\$itemCompiler\$platform\$configuration\$itemProject\"
    if ((Test-Path $directoryToCopy) -eq $false)
    {
        FatalError "Unable to locate '$directoryToCopy'."
    }

    if ($deployToAppX -eq $true)
    {
        DeployDirectory $directoryToCopy "$thisProjectOutDir\AppX\" [string]"true" $true
    }

    DeployDirectory $directoryToCopy $thisProjectOutDir [string]"true" $true
}

Write-Output "Finished copying dependencies for '$projectName'."
