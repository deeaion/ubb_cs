$param1 = $args[0] # Name of the .exe file
$param2 = $args[1] # Number of runs
$param3 = $args[2] # Number of threads
$param4 = $args[3] # Input file
$param5 = $args[4] # Matrix type
$param6 = $args[5] # variant
Write-Host "Executable: $param1"
Write-Host "Number of runs: $param2"
Write-Host "Number of threads: $param3"
Write-Host "Input file: $param4"
Write-Host "Matrix type: $param5"

$suma = 0
$validRuns = 0

for ($i = 0; $i -lt $param2; $i++) {
    Write-Host "Run number" ($i + 1)
  
    # Capture the output of the program
    $output = & .\$param1 $param3 $param4 $param5 $param6 2>&1 | Out-String

    # Debugging captured output
    Write-Host "Captured output: $output"

    # Clean up the captured output and split into lines
    $lines = $output.Split("`n") | ForEach-Object { $_.Trim() } | Where-Object { $_ -ne "" }
    Write-Host "Processing lines of output: $($lines -join ', ')"

    # Find the line with the numeric execution time
    $executionTimeLine = $lines | Where-Object { $_ -match '^\d+(\.\d+)?$' }

    if ($executionTimeLine) {
        # Convert the execution time to a string explicitly
        $executionTimeString = [string]$executionTimeLine

        # Log the string being processed
        Write-Host "Execution time as string: $executionTimeString"

        # Try converting explicitly via manual parsing
        try {
            $executionTime = [double]::Parse($executionTimeString, [System.Globalization.CultureInfo]::InvariantCulture)
            Write-Host "Converted execution time: $executionTime"
        } catch {
            Write-Host "Error converting execution time to double: $_"
            continue
        }

        # Add to the sum and count the valid runs
        $suma += $executionTime
        $validRuns++
    } else {
        Write-Host "Error: No valid execution time found in the output."
    }
}

# Calculate the average execution time
if ($validRuns -gt 0) {
    $media = $suma / $validRuns
    Write-Host "Average execution time: $media"
} else {
    Write-Host "No valid execution times to average."
}

# Create a CSV file if it doesn't exist
if (!(Test-Path outC.csv)) {
    New-Item outC.csv -ItemType File
    Set-Content outC.csv 'File,AllocationType,NumThreads,ExecutionTime,PartitionType,Variant'
}

# Append the results to the CSV file
Add-Content outC.csv "$param4,$param6, $param3, $media,$param5,$param6"
