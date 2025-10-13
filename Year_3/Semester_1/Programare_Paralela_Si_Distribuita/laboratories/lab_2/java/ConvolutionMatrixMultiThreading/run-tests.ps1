## Test 1: N=M=10, n=m=3, p=2 (Dynamic Allocation)
#Write-Host "Running Test 1 (N=M=10, n=m=3, p=2, 10 runs, dynamic allocation)"
#./scriptJ.ps1 10 2 date10x10.txt sequential VARIANTA_1B
#./scriptJ.ps1 10 2 date10x10.txt horizontal VARIANTA_1B
#./scriptJ.ps1 10 2 date10x10.txt sequential VARIANTA_1F
#./scriptJ.ps1 10 2 date10x10.txt horizontal VARIANTA_1F
#
## Test 2: N=M=1000, n=m=5, p=2, 4, 8, 16 (Dynamic Allocation)
## p=2
Write-Host "Running Test 2a (N=M=1000, n=m=5, p=2, 10 runs, dynamic allocation)"
./scriptJ.ps1 10 2 date1000x1000.txt sequential VARIANTA_1B
./scriptJ.ps1 10 2 date1000x1000.txt horizontal VARIANTA_1B
./scriptJ.ps1 10 2 date1000x1000.txt horizontal VARIANTA_1F

# p=4
Write-Host "Running Test 2b (N=M=1000, n=m=5, p=4, 10 runs, dynamic allocation)"
./scriptJ.ps1 10 4 date1000x1000.txt horizontal VARIANTA_1B
./scriptJ.ps1 10 4 date1000x1000.txt horizontal VARIANTA_1F

# p=8
Write-Host "Running Test 2c (N=M=1000, n=m=5, p=8, 10 runs, dynamic allocation)"
./scriptJ.ps1 10 8 date1000x1000.txt horizontal VARIANTA_1B
./scriptJ.ps1 10 8 date1000x1000.txt horizontal VARIANTA_1F

# p=16
Write-Host "Running Test 2d (N=M=1000, n=m=5, p=16, 10 runs, dynamic allocation)"
./scriptJ.ps1 10 16 date1000x1000.txt horizontal VARIANTA_1B
./scriptJ.ps1 10 16 date1000x1000.txt horizontal VARIANTA_1F

# Test 3: N=M=10000, n=m=5, p=2, 4, 8, 16 (Dynamic Allocation)
# p=2
Write-Host "Running Test 3a (N=M=10000, n=m=5, p=2, 10 runs, dynamic allocation)"
./scriptJ.ps1 10 2 date10000x10000.txt sequential VARIANTA_1B
./scriptJ.ps1 10 2 date10000x10000.txt horizontal VARIANTA_1B
./scriptJ.ps1 10 2 date10000x10000.txt horizontal VARIANTA_1F

# p=4
Write-Host "Running Test 3b (N=M=10000, n=m=5, p=4, 10 runs, dynamic allocation)"
./scriptJ.ps1 10 4 date10000x10000.txt horizontal VARIANTA_1B
./scriptJ.ps1 10 4 date10000x10000.txt horizontal VARIANTA_1F

# p=8
Write-Host "Running Test 3c (N=M=10000, n=m=5, p=8, 10 runs, dynamic allocation)"
./scriptJ.ps1 10 8 date10000x10000.txt horizontal VARIANTA_1B
./scriptJ.ps1 10 8 date10000x10000.txt horizontal VARIANTA_1F

# p=16
Write-Host "Running Test 3d (N=M=10000, n=m=5, p=16, 10 runs, dynamic allocation)"
./scriptJ.ps1 10 16 date10000x10000.txt horizontal VARIANTA_1B
./scriptJ.ps1 10 16 date10000x10000.txt horizontal VARIANTA_1F