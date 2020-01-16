#########################################################
#                                                       #
#     Copyright (C) Microsoft. All rights reserved.     #
#                                                       #
#########################################################

#------------------------------------------------------------------------------

param (
    [string]$babylonRoot    = $(throw "-babylonRoot is required."),
    [string]$projectName    = $(throw "-projectName is required."),
    [string]$compiler       = $(throw "-compiler is required."),
    [string]$platform       = $(throw "-platform is required."),
    [string]$configuration  = $(throw "-configuration is required."),
    [string]$type           = $(throw "-type is required"),
    [switch]$clean          = $false
)

#------------------------------------------------------------------------------

$scriptDirectory = Split-Path $MyInvocation.MyCommand.Path
. (Join-Path $scriptDirectory Common.ps1)

#------------------------------------------------------------------------------

#
# Copies a package changelog into the image directory for the current project
#
function DeployChangelog($imageDirectory)
{
	$destinationDirectory = "$imageDirectory\doc";

	# Confirm that the $imageDirectory\doc folder exists
	if ((Test-Path $destinationDirectory) -eq $false)
	{
		New-Item "$destinationDirectory\" -type directory -force | Out-Null
	}

    # Find the project's NuGet package definition
    Get-ChildItem -Path "$babylonRoot\Build\Logs\*" -Include *.md | `

    ForEach-Object {
        if ($_.BaseName.StartsWith($projectName))
        {
            $file = $_.FullName

            Copy-Item "$file" "$destinationDirectory\changelog.md" -force | Out-Null
            Write-Output "[Copy] '$file' -> '$destinationDirectory\changelog.md'"
        }
    }
}

#------------------------------------------------------------------------------

#
# Copies an nuspec or autopkg file to the project's root image folder to be
# scraped by infrastructure.
#
function DeployPackage($packageType, $imageDirectory)
{
    # Find the project's NuGet package definition
    Get-ChildItem -Path "$babylonRoot\Build\NuGet\*" -Include *.nuspec, *.autopkg, *.targets, *.props, *.ps1 | `

    ForEach-Object {
        if ($_.BaseName.StartsWith($projectName))
        {
            $file = $_.FullName
            $fileName = $_.Name

            Copy-Item "$file" "$imageDirectory\" -force | Out-Null
            Write-Output "[Copy] '$file' -> '$imageDirectory\$fileName'"
        }
    }
}

#------------------------------------------------------------------------------

#
# Generates documentation for the current project using Doxygen. If Doxygen
# can't be located then this function simply traces and returns.
#
function DeployDocumentation()
{
    cd "$babylonRoot\Build\Documentation"

    $result = Test-CommandExists doxygen.exe
    if ($result -eq [string]"false")
    {
        Write-Output "Doxygen not located, skipping documentation step."
        return
    }

    Write-Output "Building documentation for $projectName..."
    & doxygen.exe "$projectName"
    Write-Output "Documentation generation for $projectName complete!"
}

#------------------------------------------------------------------------------

#
# Deploys a plugin output directory to the common plugin image directory for
# the given compiler, platform and configuration settings.
#
function DeployPlugin()
{
    $pluginOutDir = "$babylonRoot\Built\Out\$compiler\$platform\$configuration\$projectName"
    $pluginImageDir = "$babylonRoot\Built\Image\Plugins\$platform\$configuration"

    DeployDirectory $pluginOutDir $pluginImageDir [string]"false"
}

#------------------------------------------------------------------------------

function ProcessProjectDeploymentIncludeGroup($includeDirectory, $innerProjectName, $projectPath, $includeItem)
{
    $includeItemPath = $includeItem.path
    $includeItemType = $includeItem.type

    if ($includeItemType -eq [string]"file")
    {
        $itemToCopy = "$projectPath\$includeItemPath"
        if ((Test-Path $itemToCopy) -eq $false)
        {
            FatalError "The file '$itemToCopy' doesn't exist."
        }

        Copy-Item $itemToCopy "$includeDirectory\$innerProjectName\" -force | Out-Null
        Write-Output "[Copy] '$projectPath\$includeItemPath' -> '$includeDirectory\$includeItemPath'"
    }
    elseif ($includeItemType -eq [string]"directory")
    {
        $includeItemRecursive = $includeItem.recursive
        DeployDirectory "$projectPath\$includeItemPath" "$includeDirectory\$includeItemPath" $includeItemRecursive
    }
}

#------------------------------------------------------------------------------

function ProcessProjectDeploymentDefinition($includeDirectory, $project, $libraryDirectory)
{
    $innerProjectName   = $project.projectName
    $projectLanguage    = $project.language
    $projectCopyHeaders = $project.copyHeaders
    $projectCopyOut     = $project.copyOut
    $projectLocation    = $project.location

    if ($projectCopyOut -eq [string]"true")
    {
        $outputDirectory = "$babylonRoot\Built\Out\$compiler\$platform\$configuration\$innerProjectName"

        # Copy the contents of the output directory to image/lib/
        DeployDirectory $outputDirectory $libraryDirectory [string]"false"
    }

    # CS projects have no headers to be deployed!
    if ($projectLanguage -eq [string]"cs" -or $projectCopyHeaders -eq [string]"false")
    {
        return
    }
    
    $projectPath = "$babylonRoot\$projectLocation\$innerProjectName\cpp\Inc"
    if ((Test-Path $projectPath) -eq $false)
    {
        FatalError "The path '$projectPath' doesn't exist."
    }

    # We need to make sure the project directory exists in the deployment include folder
    New-Item "$includeDirectory\$innerProjectName\" -type directory -force | Out-Null

    if ($project.Include -ne $null)
    {
        # Individual files to copy
        $includes = $project.Include
        foreach ($include in $includes)
        {
            ProcessProjectDeploymentIncludeGroup $includeDirectory $innerProjectName $projectPath $include
        }
    }
    else
    {
        DeployDirectory "$projectPath\$innerProjectName" "$includeDirectory\$innerProjectName" "true"
    }
}

#------------------------------------------------------------------------------

function ProcessProjectDeploymentFile($file)
{
    $projectToDeploy     = $file.BabylonProjectDeployment.name
    $deployDocumentation = $file.BabylonProjectDeployment.documentation
    $packageType         = $file.BabylonProjectDeployment.package
    $imageDirectory      = "$babylonRoot\Built\Image\$projectToDeploy"
    $outputDirectory     = "$babylonRoot\Built\Out\$compiler\$platform\$configuration\$projectToDeploy"
    $includeDirectory    = "$imageDirectory\include"
    $libraryDirectory    = "$imageDirectory\lib\$compiler\$platform\$configuration"

    # Delete the current image directory if it exists
    if (($clean.IsPresent -eq $true) -and ((Test-Path $imageDirectory) -eq $true))
    {
        Write-Output "Removing existing directory '$imageDirectory' due to -clean flag."
        
        if ((Test-Path "$imageDirectory\doc") -eq $true)
        {
            Write-Output "Removing existing directory '$imageDirectory\doc' due to -clean flag."
            Remove-Item -Recurse -Force $imageDirectory\doc | Out-Null
        }
        if ((Test-Path $includeDirectory) -eq $true)
        {
            Write-Output "Removing existing directory '$includeDirectory' due to -clean flag."
            Remove-Item -Recurse -Force $includeDirectory | Out-Null
        }
    }

    # Create required directories if they don't already exist
    if ((Test-Path $includeDirectory) -eq $false)
    {
        New-Item $includeDirectory -type directory -force | Out-Null
    }
    if ((Test-Path $libraryDirectory) -eq $false)
    {
        New-Item $libraryDirectory -type directory -force | Out-Null
    }
    if ((Test-Path $outputDirectory) -eq $false)
    {
        FatalError "The directory '$outputDirectory' does not exist. $projectToDeploy was not fully deployed."
    }
    
    # Copy the contents of the output directory to image/lib/
    DeployDirectory $outputDirectory $libraryDirectory [string]"false"

    # Copy include files
    $projects = $file.BabylonProjectDeployment.Project
    foreach ($project in $projects)
    {
        ProcessProjectDeploymentDefinition $includeDirectory $project $libraryDirectory
    }

    # Now we generate documentation for the deployable project if required (Release build only)
    if (($deployDocumentation -eq [string]"true") -and ($configuration -eq [string]"Release"))
    {
        DeployDocumentation
    }

    # Copy the NuGet package definition for the project if we need it
    if (($packageType -eq [string]"nuspec") -or ($packageType -eq [string]"autopkg"))
    {
        DeployPackage $packageType $imageDirectory
    }

	# Deploy the changelog for the package
	DeployChangelog $imageDirectory
}

#------------------------------------------------------------------------------

function DeployProject()
{
    cd "$babylonRoot\Build\Deployment"

    # Get all XML project deployment definitions from the current directory
    Get-ChildItem "." -Filter "$projectName.xml" | `

    Foreach-Object {
        [xml]$file = Get-Content $_.FullName

        ProcessProjectDeploymentFile $file
    }
}

#------------------------------------------------------------------------------

Write-Output "Deploying $projectName..."

if ($type -eq [string]"project")
{
    DeployProject "$babylonRoot" $projectName $compiler $platform $configuration $clean
}
elseif ($type -eq [string]"plugin")
{
    DeployPlugin "$babylonRoot" $projectName $compiler $platform $configuration
}
else
{
    FatalError "Invalid deployment type"
}

Write-Output "$projectName deployment complete!"

#------------------------------------------------------------------------------
