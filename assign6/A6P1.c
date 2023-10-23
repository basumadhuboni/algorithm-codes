#include <stdio.h>

int main() {
    int n,i,j;
    printf("Enter the number of players: ");
    scanf("%d",&n);

    int arr[n][n];
   for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        if(j==0){
            arr[i][j]=1;
        }
        else{
            arr[i][j]=0;
        }
    }
   }
   for(i=0;i<n;i++){
    for(j=0;j<=i;j++){
        if(j==0){
            arr[i][j]=1;
        }
        else if(j==i){
            arr[i][j]=(jt+1)*arr[i-1][j-1];
        }
        else{
            arr[i][j]=(j+1)*(arr[i-1][j-1]+arr[i-1][j]);
        }
    }
   }
   printf("the dp table is like \n");
   for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        printf("%d ",arr[i][j]);
    }
    printf("\n");
   }
    return 0;
}