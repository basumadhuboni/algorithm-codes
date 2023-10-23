#include <stdio.h>

int main() {
    int n, m;
    printf("Enter the number of rows\n");
    scanf("%d", &n);
    printf("Enter the number of columns\n");
    scanf("%d", &m);

    int a[n][m];
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    int b[n][m];
    for (int i = 0; i < n; i++) { // initializing all elements in b to 1
        for (int j = 0; j < m; j++) {
            b[i][j] = 1;
        }
    }

    for (int j = m - 2; j >= 0; j--) { // for filling the last row which  has i==n-1 
        if (a[n - 1][j] > a[n - 1][j + 1])
            b[n - 1][j] = b[n - 1][j + 1] + 1;
    }

    for (int i = n - 2; i >= 0; i--) { //for filling the last coloumn which has j=m-1
        if (a[i][m - 1] > a[i + 1][m - 1])
            b[i][m - 1] = b[i + 1][m - 1] + 1;
    }
    //filling rest of the elements
    for (int i = n - 2; i >= 0; i--) {
        for (int j = m - 2; j >= 0; j--) {
            if (a[i][j] > a[i + 1][j] && a[i][j] > a[i][j + 1])
                b[i][j] = 1 + ((b[i][j + 1] > b[i + 1][j]) ? b[i][j + 1] : b[i + 1][j]);
            else if (a[i][j] > a[i + 1][j] && a[i][j] < a[i][j + 1])
                b[i][j] = 1 + b[i + 1][j];
            else if (a[i][j] < a[i + 1][j] && a[i][j] > a[i][j + 1])
                b[i][j] = 1 + b[i][j + 1];
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i][j] >= max)
                max = b[i][j];
        }
    }
    printf("Max length is %d\n", max);
    return 0;
}