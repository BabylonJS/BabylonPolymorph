#########################################################
#                                                       #
#     Copyright (C) Microsoft. All rights reserved.     #
#                                                       #
#########################################################

#------------------------------------------------------------------------------

#
# Writes an error message via Write-Error and exists with code 1
#
# Sample usage:
#   FatalError "File not found."
#
function FatalError($message)
{
    Write-Output $message
    exit(1)
}

#------------------------------------------------------------------------------

#
# Writes a warning message via Write-Output
#
# Sample usage:
#   FatalError "File not found."
#
function Warning($message)
{
    Write-Output $message
}

#------------------------------------------------------------------------------

#
# Returns "true" if the command exists, "false" otherwise
#
# Sample usage:
#   if ((Test-CommandExists doxygen) -eq $true) {
#       # Use Doxygen    
#   }
#
function Test-CommandExists($command)
{
    $oldPreference = $ErrorActionPreference
    $ErrorActionPreference = 'stop'

    try
    {
        if (Get-Command $command)
        {
            "true"
        }
    }
    catch
    {
        "false"
    }
    finally
    {
        $ErrorActionPreference=$oldPreference
    }
}

#------------------------------------------------------------------------------

#
# Copies the contents of one directory $path to another directory $deployPath
# with optional recursion via the $recursive switch
#
# Sample usage:
#   DeployDirectory
#       "C:\Spectre\Lift\Shared\Framework\cpp\Inc\Framework"
#       "C:\Spectre\Lift\Built\Image\PluginSDK\include\Framework"
#       [string]"false"
#
function DeployDirectory([string]$path, [string]$deployPath, [string]$recursive, [bool]$warnOnMissing = $false)
{
    if ((Test-Path $path) -eq $false)
    {
        if ($warnOnMissing -eq $false)
        {
            FatalError "Error: The path '$path' doesn't exist."
        }
        else
        {
            Warning "Warning: The path '$path' doesn't exist."
        }
    }

    if ((Test-Path $deployPath) -eq $false)
    {
        New-Item $deployPath -type directory -force | Out-Null
    }

    if ($recursive -eq "true")
    {
        Get-ChildItem $path | ?{ $_.PSIsContainer } | `
        Foreach-Object {
            $dirName = $_.Name
            $dirPath = $_.FullName

            Write-Output "[Copy Directory] '$dirPath\$dirName' -> '$deployPath\$dirName'"
            DeployDirectory $dirPath "$deployPath\$dirName" $recursive
        }
    }

    Get-ChildItem $path -Filter "*.*" | ?{ $_.PSIsContainer -eq $false } | `
    Foreach-Object {
        $fileName = $_.Name
        $filePath = $_.FullName

        $copied = $false
        $retriesLeft = 10
        while(-not $copied -and ($retriesLeft -gt 0)) {
            try {
                Copy-Item $filePath "$deployPath\$fileName" -force | Out-Null
                $copied = $true
            } catch {
                Start-Sleep -Milliseconds 500
                --$retriesLeft
            }
        }
        if (-not $copied) {
            Write-Output "[Copy-ERROR] '$filePath' -> '$deployPath\$fileName'"
            exit 1
        }


        Write-Output "[Copied] '$filePath' -> '$deployPath\$fileName'"
    }
}

#------------------------------------------------------------------------------
