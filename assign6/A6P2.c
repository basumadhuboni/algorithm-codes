#include <stdio.h>

int main() {
    int n, m, i, j, row, col, k, e, b, r;

    printf("Enter number of rows: ");
    scanf("%d", &n);
    printf("Enter number of columns: ");
    scanf("%d", &m);

    int arr[n][m];
    printf("Enter the array:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("The array is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    int arr2[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            row = i, col = j, k = 1,b,r;
            e = arr[i][j];
             if(row==(n-1) && col==(m-1)){
                k=1;
             }
             else if(row==(n-1)){
                r=arr[row][col+1];
                while(e>r && col<m){
                    k++;
                    col++;
                    r=arr[row][col];
                }
             }  
             else if(col==(m-1)){
                b=arr[i+1][j];
                while(e>b && row<n){
                    k++;
                    row++;
                    r=arr[row][col];
                }
             } 
             else{
                r=arr[row][col+1];
                b=arr[row+1][col];
                if(e>b && e>r){
                    if(b>r){
                       k++;
                       row++;
                    }
                    else if(r>b){

                    }
                }
                else if(e>b){

                }
                else if(e>r){

                }
                else{

                }
             }
            arr2[i][j] = k; // Moved assignment inside the condition
        }
    }


    printf("The dp table is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }

    return 0;
}