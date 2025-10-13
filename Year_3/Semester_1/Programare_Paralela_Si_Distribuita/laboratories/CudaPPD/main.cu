#include <iostream>
#include <fstream>
#include <cuda_runtime.h>

_global_ void matrixMultiplyKernel(float* A, float* B, float* C, int widthA, int heightA, int widthB) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;

    if (row < heightA && col < widthB) {
        float value = 0.0f;
        for (int k = 0; k < widthA; ++k) {
            value += A[row * widthA + k] * B[k * widthB + col];
        }
        C[row * widthB + col] = value;
    }
}

void matrixMultiply(float* A, float* B, float* C, int widthA, int heightA, int widthB, dim3 blockDim, dim3 gridDim) {
    float *d_A, *d_B, *d_C;

    size_t sizeA = widthA * heightA * sizeof(float);
    size_t sizeB = widthB * widthA * sizeof(float);
    size_t sizeC = widthB * heightA * sizeof(float);

    cudaMalloc(&d_A, sizeA);
    cudaMalloc(&d_B, sizeB);
    cudaMalloc(&d_C, sizeC);

    cudaMemcpy(d_A, A, sizeA, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, B, sizeB, cudaMemcpyHostToDevice);

    matrixMultiplyKernel<<<gridDim, blockDim>>>(d_A, d_B, d_C, widthA, heightA, widthB);

    cudaMemcpy(C, d_C, sizeC, cudaMemcpyDeviceToHost);

    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);
}

void readMatrix(const char* filename, float*& matrix, int& width, int& height) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        exit(1);
    }

    file >> height >> width;
    matrix = new float[width * height];
    for (int i = 0; i < width * height; ++i) {
        file >> matrix[i];
    }

    file.close();
}

int main(int argc, char** argv) {
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " <matrixA_file> <matrixB_file> <blockDimX> <blockDimY>" << std::endl;
        return 1;
    }

    const char* matrixAFile = argv[1];
    const char* matrixBFile = argv[2];
    int blockDimX = std::stoi(argv[3]);
    int blockDimY = std::stoi(argv[4]);

    float *A, *B, *C;
    int widthA, heightA, widthB, heightB;

    readMatrix(matrixAFile, A, widthA, heightA);
    readMatrix(matrixBFile, B, widthB, heightB);

    if (widthA != heightB) {
        std::cerr << "Matrix dimensions do not match for multiplication!" << std::endl;
        delete[] A;
        delete[] B;
        return 1;
    }

    C = new float[heightA * widthB];

    dim3 blockDim(blockDimX, blockDimY);
    dim3 gridDim((widthB + blockDim.x - 1) / blockDim.x, (heightA + blockDim.y - 1) / blockDim.y);

    matrixMultiply(A, B, C, widthA, heightA, widthB, blockDim, gridDim);

    // Print a small part of the result matrix for verification
    std::cout << "Result matrix C (first 10 elements):" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}