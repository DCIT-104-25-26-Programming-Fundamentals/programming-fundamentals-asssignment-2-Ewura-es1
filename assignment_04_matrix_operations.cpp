// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
const int MAX_SIZE = 10;

void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols, string name);
void printMatrix(const int mat[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(const int input[MAX_SIZE][MAX_SIZE], int output[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int M, int N, int P);

int main() {
    int rowsA, colsA, rowsB, colsB;

    cout << "========================================\n";
    cout << "PART A: Matrix Transpose\n";
    cout << "========================================\n";
    cout << "Enter number of rows for Matrix: ";
    cin >> rowsA;
    cout << "Enter number of columns for Matrix: ";
    cin >> colsA;

    int matrixA[MAX_SIZE][MAX_SIZE];
    int transposed[MAX_SIZE][MAX_SIZE];

    readMatrix(matrixA, rowsA, colsA, "Matrix");

    cout << "\nOriginal Matrix:\n";
    printMatrix(matrixA, rowsA, colsA);
    transposeMatrix(matrixA, transposed, rowsA, colsA);
    cout << "\nTransposed Matrix:\n";
    printMatrix(transposed, colsA, rowsA);

    cout << "\n========================================\n";
    cout << "PART B: Matrix Addition\n";
    cout << "========================================\n";
    cout << "Enter rows and columns for Addition (M x N): ";
    cin >> rowsA >> colsA;

    int addA[MAX_SIZE][MAX_SIZE];
    int addB[MAX_SIZE][MAX_SIZE];
    int sumMat[MAX_SIZE][MAX_SIZE];

    readMatrix(addA, rowsA, colsA, "Matrix 1");
    readMatrix(addA, rowsA, colsA, "matrix 2");

    addMatrices(addA, addB, sumMat, rowsA, colsA);

    cout << "\nSum Matrix:\n";
    printMatrix(sumMat, rowsA, colsA);

    cout << "\n========================================\n";
    cout << "PART C: Matrix Multiplication\n";
    cout << "========================================\n";
    cout << "Enter rows (M) and columns (N) for Matrix A: ";
    cin >> rowsA >> colsA;

    cout << "Enter rowa (must be " <<colsA << ")and columns (P) for Matrix B: ";
    cin >> rowsB >> colsB;

    if (colsA != rowsB) {
        cout << "Error: Matrix multiplication not possible! (colsA must equal rowsB)\n";
        return 1;
    }
    
    int multA[MAX_SIZE][MAX_SIZE];
    int multB[MAX_SIZE][MAX_SIZE];
    int product[MAX_SIZE][MAX_SIZE];

    readMatrix(multA, rowsA, colsA, "Matrix A");
    readMatrix(multB, rowsB, colsB, "Matrix B");

    multiplyMatrices(multA, multB, product, rowsA, colsA, colsB);

    cout << "\nProduct Matrix (A x B):\n";
    printMatrix(product, rowsA, colsB);

    return 0;
}

void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols, string name) {
    cout << "\nEntering elements for " << name << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element ["<< i << "]["<< j << "]: ";
            cin >> mat[i][j];
        }
    }
}

void printMatrix(const int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << mat[i][j];
        }
        cout << endl;
    }
}
void transposeMatrix(const int input[MAX_SIZE][MAX_SIZE], int output[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            output[j][i] = input [i][j];
        }
    }
}

void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int M, int N, int P) {
    for (int i = 0; i < M; i++){
        for (int j = 0; j < P; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
