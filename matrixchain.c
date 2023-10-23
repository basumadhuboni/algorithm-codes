#include <stdio.h>
#include <limits.h>

int MCM(int p[], int i, int j, int memo[][100]) {
    int minMultiplications = INT_MAX;
    int c = 0;
    if (i == j) {
        return 0;
    }
    else {
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        else {
            for (int k = i; k < j; k++) {
                c = MCM(p, i, k, memo) + MCM(p, k + 1, j, memo) + (p[i - 1] * p[k] * p[j]);
                minMultiplications = (c < minMultiplications) ? c : minMultiplications;
            }
            memo[i][j] = minMultiplications;
            return minMultiplications;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    int p[n + 1], i, j;
    int memo[n][100];  // Assuming a maximum size of 100 for the second dimension

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            memo[i][j] = -1;
        }
    }

    for (int i = 0; i <= n; i++) {
        printf("Enter the element %d: ", (i + 1));
        scanf("%d", &p[i]);
    }

    printf("Minimum number of multiplications is: %d\n", MCM(p, 1, n, memo));

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", memo[i][j]);
        }
        printf("\n");
    }
    return 0;
}