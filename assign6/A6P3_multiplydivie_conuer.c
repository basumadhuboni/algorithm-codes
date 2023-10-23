#include <stdio.h>

void multiply(int n, int A[n][n], int B[n][n], int C[n][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int i, j;
    int newSize = n / 2;
    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];

    // Divide A and B into 4 sub-matrices
    for (i = 0; i < newSize; i++) {
        for (j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    int P1[newSize][newSize], P2[newSize][newSize], P3[newSize][newSize], P4[newSize][newSize], P5[newSize][newSize], P6[newSize][newSize], P7[newSize][newSize],P8[newSize][newSize];

    // Calculate the 8 products
    multiply(newSize, A11, B11, P1);
    multiply(newSize, A12, B21, P2);
    multiply(newSize, A11, B12, P3);
    multiply(newSize, A12, B22, P4);
    multiply(newSize, A21, B11, P5);
    multiply(newSize, A22, B21, P6);
    multiply(newSize, A21, B12, P7);
    multiply(newSize, A22, B22, P8);
    // Combine the results to get C
    for (i = 0; i < newSize; i++) {
        for (j = 0; j < newSize; j++) {
            C11[i][j] = P1[i][j] + P2[i][j];
            C12[i][j] = P3[i][j] + P4[i][j];
            C21[i][j] = P5[i][j] + P6[i][j];
            C22[i][j] = P7[i][j]+P8[i][j];

            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

int main() {
    int n = 2; // Change n to your desired size (2^k)
    int A[n][n], B[n][n], C[n][n];
    
    printf("enter the matrix A \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d",&A[i][j]);
        }
    }

    printf("enter the matrix B \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d",&B[i][j]);
        }
    }

    multiply(n, A, B, C);

    // Print the result matrix C
    printf("Resultant Matrix C:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
  
    return 0;
}