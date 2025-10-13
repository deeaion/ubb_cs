# Test 1: N=M=10, n=m=3, p=4 (Dynamic Allocation)
Write-Host "Running Test 1 (N=M=10, n=m=3, p=4, dynamic allocation)"
./scriptC.ps1 Solution.exe 10 4 date10x10.txt sequential dynamic
./scriptC.ps1 Solution.exe 10 4 date10x10.txt horizontal dynamic
./scriptC.ps1 Solution.exe 10 4 date10x10.txt vertical dynamic
./scriptC.ps1 Solution.exe 10 4 date10x10.txt block dynamic
./scriptC.ps1 Solution.exe 10 4 date10x10.txt linear dynamic
./scriptC.ps1 Solution.exe 10 4 date10x10.txt cyclic dynamic

# Test 2: N=M=1000, n=m=5, p=2,4,8,16 (Dynamic Allocation)
# p=2
Write-Host "Running Test 2 (N=M=1000, n=m=5, p=2, dynamic allocation)"
./scriptC.ps1 Solution.exe 10 2 date1000x1000.txt sequential dynamic
./scriptC.ps1 Solution.exe 10 2 date1000x1000.txt horizontal dynamic
./scriptC.ps1 Solution.exe 10 2 date1000x1000.txt vertical dynamic
./scriptC.ps1 Solution.exe 10 2 date1000x1000.txt block dynamic
./scriptC.ps1 Solution.exe 10 2 date1000x1000.txt linear dynamic
./scriptC.ps1 Solution.exe 10 2 date1000x1000.txt cyclic dynamic

# p=4
Write-Host "Running Test 2 (N=M=1000, n=m=5, p=4, dynamic allocation)"
./scriptC.ps1 Solution.exe 10 4 date1000x1000.txt horizontal dynamic
./scriptC.ps1 Solution.exe 10 4 date1000x1000.txt vertical dynamic
./scriptC.ps1 Solution.exe 10 4 date1000x1000.txt block dynamic
./scriptC.ps1 Solution.exe 10 4 date1000x1000.txt linear dynamic
./scriptC.ps1 Solution.exe 10 4 date1000x1000.txt cyclic dynamic

# p=8
Write-Host "Running Test 2 (N=M=1000, n=m=5, p=8, dynamic allocation)"
./scriptC.ps1 Solution.exe 10 8 date1000x1000.txt horizontal dynamic
./scriptC.ps1 Solution.exe 10 8 date1000x1000.txt vertical dynamic
./scriptC.ps1 Solution.exe 10 8 date1000x1000.txt block dynamic
./scriptC.ps1 Solution.exe 10 8 date1000x1000.txt linear dynamic
./scriptC.ps1 Solution.exe 10 8 date1000x1000.txt cyclic dynamic

# p=16
Write-Host "Running Test 2 (N=M=1000, n=m=5, p=16, dynamic allocation)"
./scriptC.ps1 Solution.exe 10 16 date1000x1000.txt horizontal dynamic
./scriptC.ps1 Solution.exe 10 16 date1000x1000.txt vertical dynamic
./scriptC.ps1 Solution.exe 10 16 date1000x1000.txt block dynamic
./scriptC.ps1 Solution.exe 10 16 date1000x1000.txt linear dynamic
./scriptC.ps1 Solution.exe 10 16 date1000x1000.txt cyclic dynamic

# Test 3: N=10, M=10000, n=m=5, p=2,4,8,16 (Dynamic Allocation)
# p=2
Write-Host "Running Test 3 (N=10, M=10000, n=m=5, p=2, dynamic allocation)"
./scriptC.ps1 Solution.exe 10 2 date10x10000.txt sequential dynamic
./scriptC.ps1 Solution.exe 10 2 date10x10000.txt horizontal dynamic
./scriptC.ps1 Solution.exe 10 2 date10x10000.txt vertical dynamic
./scriptC.ps1 Solution.exe 10 2 date10x10000.txt block dynamic
./scriptC.ps1 Solution.exe 10 2 date10x10000.txt linear dynamic
./scriptC.ps1 Solution.exe 10 2 date10x10000.txt cyclic dynamic

# p=4
Write-Host "Running Test 3 (N=10, M=10000, n=m=5, p=4, dynamic allocation)"
./scriptC.ps1 Solution.exe 10 4 date10x10000.txt horizontal dynamic
./scriptC.ps1 Solution.exe 10 4 date10x10000.txt vertical dynamic
./scriptC.ps1 Solution.exe 10 4 date10x10000.txt block dynamic
./scriptC.ps1 Solution.exe 10 4 date10x10000.txt linear dynamic
./scriptC.ps1 Solution.exe 10 4 date10x10000.txt cyclic dynamic

# p=8
Write-Host "Running Test 3 (N=10, M=10000, n=m=5, p=8, dynamic allocation)"
./scriptC.ps1 Solution.exe 10 8 date10x10000.txt horizontal dynamic
./scriptC.ps1 Solution.exe 10 8 date10x10000.txt vertical dynamic
./scriptC.ps1 Solution.exe 10 8 date10x10000.txt block dynamic
./scriptC.ps1 Solution.exe 10 8 date10x10000.txt linear dynamic
./scriptC.ps1 Solution.exe 10 8 date10x10000.txt cyclic dynamic

# p=16
Write-Host "Running Test 3 (N=10, M=10000, n=m=5, p=16, dynamic allocation)"
./scriptC.ps1 Solution.exe 10 16 date10x10000.txt horizontal dynamic
./scriptC.ps1 Solution.exe 10 16 date10x10000.txt vertical dynamic
./scriptC.ps1 Solution.exe 10 16 date10x10000.txt block dynamic
./scriptC.ps1 Solution.exe 10 16 date10x10000.txt linear dynamic
./scriptC.ps1 Solution.exe 10 16 date10x10000.txt cyclic dynamic

# Test 4: N=10000, M=10, n=m=5, p=2,4,8,16 (Dynamic Allocation)
# p=2
Write-Host "Running Test 4 (N=10000, M=10, n=m=5, p=2, dynamic allocation)"
./scriptC.ps1 Solution.exe 10 2 date10000x10.txt sequential dynamic
./scriptC.ps1 Solution.exe 10 2 date10000x10.txt horizontal dynamic
./scriptC.ps1 Solution.exe 10 2 date10000x10.txt vertical dynamic
./scriptC.ps1 Solution.exe 10 2 date10000x10.txt block dynamic
./scriptC.ps1 Solution.exe 10 2 date10000x10.txt linear dynamic
./scriptC.ps1 Solution.exe 10 2 date10000x10.txt cyclic dynamic

# p=4
Write-Host "Running Test 4 (N=10000, M=10, n=m=5, p=4, dynamic allocation)"
./scriptC.ps1 Solution.exe 10 4 date10000x10.txt horizontal dynamic
./scriptC.ps1 Solution.exe 10 4 date10000x10.txt vertical dynamic
./scriptC.ps1 Solution.exe 10 4 date10000x10.txt block dynamic
./scriptC.ps1 Solution.exe 10 4 date10000x10.txt linear dynamic
./scriptC.ps1 Solution.exe 10 4 date10000x10.txt cyclic dynamic

# p=8
Write-Host "Running Test 4 (N=10000, M=10, n=m=5, p=8, dynamic allocation)"
./scriptC.ps1 Solution.exe 10 8 date10000x10.txt horizontal dynamic
./scriptC.ps1 Solution.exe 10 8 date10000x10.txt vertical dynamic
./scriptC.ps1 Solution.exe 10 8 date10000x10.txt block dynamic
./scriptC.ps1 Solution.exe 10 8 date10000x10.txt linear dynamic
./scriptC.ps1 Solution.exe 10 8 date10000x10.txt cyclic dynamic

# p=16
Write-Host "Running Test 4 (N=10000, M=10, n=m=5, p=16, dynamic allocation)"
./scriptC.ps1 Solution.exe 10 16 date10000x10.txt horizontal dynamic
./scriptC.ps1 Solution.exe 10 16 date10000x10.txt vertical dynamic
./scriptC.ps1 Solution.exe 10 16 date10000x10.txt block dynamic
./scriptC.ps1 Solution.exe 10 16 date10000x10.txt linear dynamic
./scriptC.ps1 Solution.exe 10 16 date10000x10.txt cyclic dynamic

# Test 5: N=10000, M=10000, n=m=5, p=2,4,8,16 (Dynamic Allocation)
# p=2
Write-Host "Running Test 5 (N=10000, M=10000, n=m=5, p=2, dynamic allocation)"
./scriptC.ps1 Solution.exe 10 2 date10000x10000.txt sequential dynamic
./scriptC.ps1 Solution.exe 10 2 date10000x10000.txt horizontal dynamic
./scriptC.ps1 Solution.exe 10 2 date10000x10000.txt vertical dynamic
./scriptC.ps1 Solution.exe 10 2 date10000x10000.txt block dynamic
./scriptC.ps1 Solution.exe 10 2 date10000x10000.txt linear dynamic
./scriptC.ps1 Solution.exe 10 2 date10000x10000.txt cyclic dynamic

# p=4
Write-Host "Running Test 5 (N=10000, M=10000, n=m=5, p=4, dynamic allocation)"
./scriptC.ps1 Solution.exe 10 4 date10000x10000.txt horizontal dynamic
./scriptC.ps1 Solution.exe 10 4 date10000x10000.txt vertical dynamic
./scriptC.ps1 Solution.exe 10 4 date10000x10000.txt block dynamic
./scriptC.ps1 Solution.exe 10 4 date10000x10000.txt linear dynamic
./scriptC.ps1 Solution.exe 10 4 date10000x10000.txt cyclic dynamic

# p=8
Write-Host "Running Test 5 (N=10000, M=10000, n=m=5, p=8, dynamic allocation)"
./scriptC.ps1 Solution.exe 10 8 date10000x10000.txt horizontal dynamic
./scriptC.ps1 Solution.exe 10 8 date10000x10000.txt vertical dynamic
./scriptC.ps1 Solution.exe 10 8 date10000x10000.txt block dynamic
./scriptC.ps1 Solution.exe 10 8 date10000x10000.txt linear dynamic
./scriptC.ps1 Solution.exe 10 8 date10000x10000.txt cyclic dynamic

# p=16
Write-Host "Running Test 5 (N=10000, M=10000, n=m=5, p=16, dynamic allocation)"
./scriptC.ps1 Solution.exe 10 16 date10000x10000.txt horizontal dynamic
./scriptC.ps1 Solution.exe 10 16 date10000x10000.txt vertical dynamic
./scriptC.ps1 Solution.exe 10 16 date10000x10000.txt block dynamic
./scriptC.ps1 Solution.exe 10 16 date10000x10000.txt linear dynamic
./scriptC.ps1 Solution.exe 10 16 date10000x10000.txt cyclic dynamic
