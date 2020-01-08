Param
(
    $scriptPath,
    $outPath
)
Write-Host "Script: ${scriptPath}"
Write-Host "Output: ${outPath}"
cd (Split-Path $scriptPath -Parent)
powershell -ExecutionPolicy Bypass $scriptPath -outPath $outPath