#include<stdio.h>
int lcw(char a[],char b[],int n,int m){
    int dp[n+1][m+1],i,j,maxi,maxj;
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
          dp[i][j]=0;
        }
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
           if(a[j-1]==b[i-1]){
             dp[i][j]=1+dp[i-1][j-1];
             maxi=i;
             maxj=j;
           }
        }
    }
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
          printf("%d",dp[i][j]);
        }
        printf("\n");
    }
    while(dp[maxi][maxj]!=0){
      printf("%c ",b[maxj-1]);
      maxi--;
      maxj--;
    }
    int max=0;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
           if(max<dp[i][j]){
             max=dp[i][j];
           }
        }
    }

    return max;
}
int main(){
    int len1,len2,i,j;
   printf("enter the lenght offirst string");
   scanf("%d",&len1);
   printf("enter length of second string");
   scanf("%d",&len2);
   char a[len1],b[len2];
   printf("enter the  first string");
   for(i=0;i<len1;i++){
     scanf(" %c",&a[i]);
   }
   printf("enter the second string");
   for(i=0;i<len2;i++){
     scanf(" %c",&b[i]);
   }
   int c=lcw(a,b,len1,len2);

   printf("%d ",c);
}