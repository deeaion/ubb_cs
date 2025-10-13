# Parameters
$param1 = $args[0] # No of threads
$param2 = $args[1] # No of runs
$param3 = $args[2] # Input file
$param4 = $args[3] # Method name
# write them to the console
Write-Host "Threads: $param1"
Write-Host "Runs: $param2"
Write-Host "Input file: $param3"
Write-Host "Method name: $param4"

# Initialize the sum of execution times
$suma = 0

for ($i = 0; $i -lt $param3; $i++) {
    Write-Host "Run number" ($i+1)

    # Execute Gradle wrapper command and capture the output
    $output = & .\gradlew run --args="$param1 $param3 $param4" | Out-String

    # Debugging: Print the full output to see what's being captured
    Write-Host "Full Gradle Output: $output"

    # Extract only numeric lines which represent the execution time
    $lines = $output.Split("`n")
    foreach ($line in $lines) {
        $trimmedLine = $line.Trim()
        # Check if the line is a valid number (i.e., the execution time)
        if ($trimmedLine -match '^\d+(\.\d+)?$') {
            $executionTime = [double]$trimmedLine
            Write-Host "Execution time: $executionTime"
            $suma += $executionTime
            break
        }
    }
}

# Calculate the average execution time, ensuring there were valid runs
if ($suma -gt 0) {
    $media = $suma / $param3
    Write-Host "Average execution time: $media"

    # Create a CSV file if it doesn't exist
    if (!(Test-Path outJ.csv)) {
        New-Item outJ.csv -ItemType File
        Set-Content outJ.csv 'MatrixType,Threads,ExecutionTime'
    }

    # Append results to CSV
    Add-Content outJ.csv "$param6,$param2,$media"

    Write-Host "Results written to outJ.csv"
} else {
    Write-Host "No valid execution times to average."
}
