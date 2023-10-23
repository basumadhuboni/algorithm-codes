#include<stdio.h>
int main()
{
  int n,m,a,i,k=0,j;
  printf("enter value of n");
  scanf("%d",&n);
  printf("enter value of arg");
  scanf("%d",&a);
  for(i=0;i<n;i++){
     if(i%(a+1)==0){
        for(j=0;j<n;j++){
            printf("*");
        }
        printf("\n");
        k=k+1;
     }
     else{

         if(k%2!=0){//odd
                for(j=0;j<(n-1);j++)
                {
                 printf(" ");
                 }
                printf("*\n");
              
        }
         
        
        else{ //even
             
                  printf("*");
                for(j=0;j<(n-1);j++)
                {
                 printf(" ");
                 }
               printf("\n");
           
        }
        
     }
  } 
}
