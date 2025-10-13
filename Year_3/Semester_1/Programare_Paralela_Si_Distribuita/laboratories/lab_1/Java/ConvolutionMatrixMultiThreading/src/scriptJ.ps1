# Parameters
$param1 = $args[0] # Main class name
$param2 = $args[1] # No of threads
$param3 = $args[2] # No of runs
$param4 = $args[3] # Input file
$param5 = $args[4] # Method name

$suma = 0

for ($i = 0; $i -lt $param3; $i++) {
    Write-Host "Run number" ($i+1)
    
    # Execute Gradle run command and capture the output
    $output = & gradle run -Pargs="$param1 $param2 $param4 $param5" | Out-String
    
    # Assuming the last line of output is the execution time in milliseconds
    $lastLine = $output.Split("`n")[-2].Trim() # Get second to last line and trim spaces
    Write-Host "Execution time:" $lastLine
    
    # Add the execution time to the sum
    $suma += [int]$lastLine
}

# Calculate the average execution time
$media = $suma / $param3
Write-Host "Average execution time:" $media

# Create a CSV file if it doesn't exist
if (!(Test-Path outJ.csv)) {
    New-Item outJ.csv -ItemType File
    Set-Content outJ.csv 'File,Threads,ExecutionTime,PartitionType'
}

# Append results to CSV
Add-Content outJ.csv "$param4,$param2,$media,$param6"

Write-Host "Results written to outJ.csv"
