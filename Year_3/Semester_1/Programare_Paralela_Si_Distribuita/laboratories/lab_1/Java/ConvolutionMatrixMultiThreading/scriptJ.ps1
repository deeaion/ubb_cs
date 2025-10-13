# Parameters
$param1 = $args[0] # No of threads
$param2 = $args[1] # No of runs
$param3 = $args[2] # Input file
$param4 = $args[3] # Method name

Write-Host "Threads: $param1"
Write-Host "Runs: $param2"
Write-Host "Input file: $param3"
Write-Host "Method name: $param4"

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
        Set-Content outJ.csv 'MatrixType,File,Threads,ExecutionTime'
    }

    Add-Content outJ.csv "$param4,$param3,$param1,$media"

    Write-Host "Results written to outJ.csv"
} else {
    Write-Host "No valid execution times to average."
}
