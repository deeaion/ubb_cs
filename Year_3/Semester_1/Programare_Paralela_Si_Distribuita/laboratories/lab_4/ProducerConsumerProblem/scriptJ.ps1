# Parameters
$param1 = $args[0] # type
$param2 = $args[1] # No of runs
$param3 = $args[2] # reader threads
$param4 = $args[3] # writer threads

if ($param1 -eq "sequential") {
    $param1 = "sequential"
} elseif ($param1 -eq "parallel") {
    $param1 = "parallel"
} else {
    Write-Host "Invalid type. Must be 'sequential' or 'parallel'."
    exit
}

if ($param2 -eq $null -or $param2 -lt 1) {
    Write-Host "Invalid number of runs. Must be a positive integer."
    exit
}

if ($param3 -eq $null -or $param3 -lt 0) {
    Write-Host "Invalid number of reader threads. Must be a non-negative integer."
    exit
}

if ($param4 -eq $null -or $param4 -lt 0) {
    Write-Host "Invalid number of writer threads. Must be a non-negative integer."
    exit
}
$suma = 0

for ($i = 0; $i -lt $param2; $i++) {
    Write-Host "Run number" ($i+1)

    $output = & .\gradlew run --args="$param1 $param3 $param4" | Out-String

    Write-Host "Full Gradle Output: $output"

    $lines = $output.Split("`n")
    foreach ($line in $lines) {
        $trimmedLine = $line.Trim()
        if ($trimmedLine -match '^\d+(\.\d+)?$') {
            $executionTime = [double]$trimmedLine
            Write-Host "Execution time: $executionTime"
            $suma += $executionTime
            break
        }
    }
}

if ($suma -gt 0) {
    $media = $suma / $param2
    Write-Host "Average execution time: $media"

    if (!(Test-Path outJ.csv)) {
        New-Item outJ.csv -ItemType File
        Set-Content outJ.csv 'Type,NOOfReaderThreads,NOOfWriterThreads,Time'

    }

    Add-Content outJ.csv "$param1,$param3,$param4,$media"

    Write-Host "Results written to outJ.csv"
} else {
    Write-Host "No valid execution times to average."
}
