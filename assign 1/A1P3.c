#include<stdio.h>
int main()
{
  int n,i,j,k,k1,row,m,t,q,r;
  printf("enter value of n");
  scanf("%d",&n);
  int arr1[n],arr2[n],arr[n][n+n];
  printf("enter first number\n");
  for(i=0;i<n;i++){
     printf("enterdigit %d ",(i+1));
      scanf("%d",&arr1[i]);
  }
printf("enter second number\n");
  for(i=0;i<n;i++){
     printf("enterdigit %d",(i+1));
      scanf("%d",&arr2[i]);
  }
row=0;
m=2*n;

for(i=0;i<n;i++){//initializing with 0
  for(j=0;j<m;j++){
    arr[i][j]=0;
  }
}

for(i=(n-1);i>=0;i--){
   k1=m-1;
  for(t=0;t<row;t++){
    k1=k1-1;
  }
  
  q=0;
  for(j=(n-1);j>=0;j--){
     
     q=q+(arr1[j]*arr2[i]);
     r=q%10;
     q=q/10;
     arr[row][k1]=r;
    
     k1--;
  }
 
  while(q>0){
    
    arr[row][k1]=q%10;
    q=q/10;
    k1--;
  }
  
  row++;
}
for(i=0;i<n;i++){
  for(j=0;j<m;j++){
     printf("%d",arr[i][j]);
  }
  printf("\n");
}
}
