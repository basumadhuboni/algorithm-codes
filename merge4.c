#include <stdio.h>
#include <stdlib.h>

#define N 4

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

void mergeKArrays(int arr[][N], int a, int output[]) {
    int c = 0;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < N; j++)
            output[c++] = arr[i][j];
    }

    for (int i = 0; i < N * a - 1; i++) {
        for (int j = 0; j < N * a - i - 1; j++) {
            if (output[j] > output[j + 1]) {
                int temp = output[j];
                output[j] = output[j + 1];
                output[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[][N] = { { 2, 6, 12, 34 },
                     { 1, 9, 20, 1000 },
                     { 23, 34, 90, 2000 } };
    int K = sizeof(arr) / sizeof(arr[0]);

    int* output = (int*)malloc(N * K * sizeof(int));

    mergeKArrays(arr, K, output);

    printf("Merged array is:\n");
    printArray(output, N * K);

    free(output);
    return 0;
}