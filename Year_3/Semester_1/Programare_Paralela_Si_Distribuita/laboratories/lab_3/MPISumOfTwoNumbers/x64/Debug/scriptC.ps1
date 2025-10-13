$param1 = $args[0] # Name of the .exe file
$param2 = $args[1] # Number of runs
$param3 = $args[2] # Number of processes
$param4 = $args[3] # Variant (for CSV)
$param5 = $args[4] # Test (for CSV)

$suma = 0
$validRuns = 0

for ($i = 0; $i -lt $param2; $i++) {
    Write-Host "Run number" ($i + 1)
  
    # Capture the output of the program using mpiexec
    $output = & mpiexec -np $param3 .\$param1 2>&1 | Out-String

    # Debugging captured output
    Write-Host "Captured output: $output"

    # Clean up the captured output and split into lines
    $lines = $output.Split("`n") | ForEach-Object { $_.Trim() } | Where-Object { $_ -ne "" }
    Write-Host "Processing lines of output: $($lines -join ', ')"

    # Flag to mark if we have found a valid execution time
    $foundExecutionTime = $false

    # Iterate over each line until we find the first valid numeric line
    foreach ($line in $lines) {
        if ($line -match '^\d+(\.\d+)?$') {
            try {
                # Parse the matched line as a double
                $executionTime = [double]::Parse($line, [System.Globalization.CultureInfo]::InvariantCulture)
                Write-Host "Converted execution time: $executionTime"

                # Add to the sum and count the valid runs
                $suma += $executionTime
                $validRuns++
                $foundExecutionTime = $true
                break # Exit the loop once we've found the first valid execution time
            } catch {
                Write-Host "Error converting execution time to double: $_"
            }
        }
    }

    # If no valid execution time was found, log an error
    if (-not $foundExecutionTime) {
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
    Set-Content outC.csv 'Variant,NumProcesses,ExecutionTime,Test'
}

# Append the results to the CSV file
Add-Content outC.csv "$param4, $param3, $media, $param5"
