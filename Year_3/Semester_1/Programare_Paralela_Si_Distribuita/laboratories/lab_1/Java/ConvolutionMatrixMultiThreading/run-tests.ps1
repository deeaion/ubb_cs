# Test 1: N=M=10, n=m=3, p=4
Write-Host "Running Test 1 (N=M=10, n=m=3, p=4)"
./scriptJ.ps1 4 10 date10x10.txt sequential
./scriptJ.ps1 4 10 date10x10.txt horizontal
./scriptJ.ps1 4 10 date10x10.txt vertical
./scriptJ.ps1 4 10 date10x10.txt block
./scriptJ.ps1 4 10 date10x10.txt linear
./scriptJ.ps1 4 10 date10x10.txt cyclic

# Test 2: N=M=1000, n=m=5, p=2,4,8,16
# p=2
Write-Host "Running Test 2 (N=M=1000, n=m=5, p=2)"
./scriptJ.ps1 2 10 date1000x1000.txt sequential
./scriptJ.ps1 2 10 date1000x1000.txt horizontal
./scriptJ.ps1 2 10 date1000x1000.txt vertical
./scriptJ.ps1 2 10 date1000x1000.txt block
./scriptJ.ps1 2 10 date1000x1000.txt linear
./scriptJ.ps1 2 10 date1000x1000.txt cyclic

# p=4
Write-Host "Running Test 2 (N=M=1000, n=m=5, p=4)"
./scriptJ.ps1 4 10 date1000x1000.txt horizontal
./scriptJ.ps1 4 10 date1000x1000.txt vertical
./scriptJ.ps1 4 10 date1000x1000.txt block
./scriptJ.ps1 4 10 date1000x1000.txt linear
./scriptJ.ps1 4 10 date1000x1000.txt cyclic

# p=8
Write-Host "Running Test 2 (N=M=1000, n=m=5, p=8)"
./scriptJ.ps1 8 10 date1000x1000.txt horizontal
./scriptJ.ps1 8 10 date1000x1000.txt vertical
./scriptJ.ps1 8 10 date1000x1000.txt block
./scriptJ.ps1 8 10 date1000x1000.txt linear
./scriptJ.ps1 8 10 date1000x1000.txt cyclic

# p=16
Write-Host "Running Test 2 (N=M=1000, n=m=5, p=16)"
./scriptJ.ps1 16 10 date1000x1000.txt horizontal
./scriptJ.ps1 16 10 date1000x1000.txt vertical
./scriptJ.ps1 16 10 date1000x1000.txt block
./scriptJ.ps1 16 10 date1000x1000.txt linear
./scriptJ.ps1 16 10 date1000x1000.txt cyclic


# Test 3: N=10, M=10000, n=m=5, p=2,4,8,16
# p=2
Write-Host "Running Test 3 (N=10, M=10000, n=m=5, p=2)"
./scriptJ.ps1 2 10 date10x10000.txt sequential
./scriptJ.ps1 2 10 date10x10000.txt horizontal
./scriptJ.ps1 2 10 date10x10000.txt vertical
./scriptJ.ps1 2 10 date10x10000.txt block
./scriptJ.ps1 2 10 date10x10000.txt linear
./scriptJ.ps1 2 10 date10x10000.txt cyclic

# p=4
Write-Host "Running Test 3 (N=10, M=10000, n=m=5, p=4)"
./scriptJ.ps1 4 10 date10x10000.txt horizontal
./scriptJ.ps1 4 10 date10x10000.txt vertical
./scriptJ.ps1 4 10 date10x10000.txt block
./scriptJ.ps1 4 10 date10x10000.txt linear
./scriptJ.ps1 4 10 date10x10000.txt cyclic

# p=8
Write-Host "Running Test 3 (N=10, M=10000, n=m=5, p=8)"
./scriptJ.ps1 8 10 date10x10000.txt horizontal
./scriptJ.ps1 8 10 date10x10000.txt vertical
./scriptJ.ps1 8 10 date10x10000.txt block
./scriptJ.ps1 8 10 date10x10000.txt linear
./scriptJ.ps1 8 10 date10x10000.txt cyclic

# p=16
Write-Host "Running Test 3 (N=10, M=10000, n=m=5, p=16)"
./scriptJ.ps1 16 10 date10x10000.txt horizontal
./scriptJ.ps1 16 10 date10x10000.txt vertical
./scriptJ.ps1 16 10 date10x10000.txt block
./scriptJ.ps1 16 10 date10x10000.txt linear
./scriptJ.ps1 16 10 date10x10000.txt cyclic


# Test 4: N=10000, M=10, n=m=5, p=2,4,8,16
# p=2
Write-Host "Running Test 4 (N=10000, M=10, n=m=5, p=2)"
./scriptJ.ps1 2 10 date10000x10.txt sequential
./scriptJ.ps1 2 10 date10000x10.txt horizontal
./scriptJ.ps1 2 10 date10000x10.txt vertical
./scriptJ.ps1 2 10 date10000x10.txt block
./scriptJ.ps1 2 10 date10000x10.txt linear
./scriptJ.ps1 2 10 date10000x10.txt cyclic

# p=4
Write-Host "Running Test 4 (N=10000, M=10, n=m=5, p=4)"
./scriptJ.ps1 4 10 date10000x10.txt horizontal
./scriptJ.ps1 4 10 date10000x10.txt vertical
./scriptJ.ps1 4 10 date10000x10.txt block
./scriptJ.ps1 4 10 date10000x10.txt linear
./scriptJ.ps1 4 10 date10000x10.txt cyclic

# p=8
Write-Host "Running Test 4 (N=10000, M=10, n=m=5, p=8)"
./scriptJ.ps1 8 10 date10000x10.txt horizontal
./scriptJ.ps1 8 10 date10000x10.txt vertical
./scriptJ.ps1 8 10 date10000x10.txt block
./scriptJ.ps1 8 10 date10000x10.txt linear
./scriptJ.ps1 8 10 date10000x10.txt cyclic

# p=16
Write-Host "Running Test 4 (N=10000, M=10, n=m=5, p=16)"
./scriptJ.ps1 16 10 date10000x10.txt horizontal
./scriptJ.ps1 16 10 date10000x10.txt vertical
./scriptJ.ps1 16 10 date10000x10.txt block
./scriptJ.ps1 16 10 date10000x10.txt linear
./scriptJ.ps1 16 10 date10000x10.txt cyclic


# Test 5: N=10000, M=10000, n=m=5, p=2,4,8,16
# p=2
Write-Host "Running Test 5 (N=10000, M=10000, n=m=5, p=2)"
./scriptJ.ps1 2 10 date10000x10000.txt sequential
./scriptJ.ps1 2 10 date10000x10000.txt horizontal
./scriptJ.ps1 2 10 date10000x10000.txt vertical
./scriptJ.ps1 2 10 date10000x10000.txt block
./scriptJ.ps1 2 10 date10000x10000.txt linear
./scriptJ.ps1 2 10 date10000x10000.txt cyclic

# p=4
Write-Host "Running Test 5 (N=10000, M=10000, n=m=5, p=4)"
./scriptJ.ps1 4 10 date10000x10000.txt horizontal
./scriptJ.ps1 4 10 date10000x10000.txt vertical
./scriptJ.ps1 4 10 date10000x10000.txt block
./scriptJ.ps1 4 10 date10000x10000.txt linear
./scriptJ.ps1 4 10 date10000x10000.txt cyclic

# p=8
Write-Host "Running Test 5 (N=10000, M=10000, n=m=5, p=8)"
./scriptJ.ps1 8 10 date10000x10000.txt horizontal
./scriptJ.ps1 8 10 date10000x10000.txt vertical
./scriptJ.ps1 8 10 date10000x10000.txt block
./scriptJ.ps1 8 10 date10000x10000.txt linear
./scriptJ.ps1 8 10 date10000x10000.txt cyclic

# p=16
Write-Host "Running Test 5 (N=10000, M=10000, n=m=5, p=16)"
./scriptJ.ps1 16 10 date10000x10000.txt horizontal
./scriptJ.ps1 16 10 date10000x10000.txt vertical
./scriptJ.ps1 16 10 date10000x10000.txt block
./scriptJ.ps1 16 10 date10000x10000.txt linear
./scriptJ.ps1 16 10 date10000x10000.txt cyclic

