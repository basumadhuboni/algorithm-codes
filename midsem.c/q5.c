#include<stdio.h>
int max(int a,int b){
    if(a>b){
        return a;
    }
    else {
        return b;
    }
}
int largest(int arr[],int lb,int ub){
    int a,b,mid;
    int n=(ub-lb)+1;
  if(n==1){
    return n;
  }
  else if(n==2){
    if(arr[ub]<arr[lb]){
        return arr[lb];
    }
    else if(arr[ub]>arr[lb]){
        return arr[ub];
    }
  }
  else{
    mid=(lb+ub)/2;
    a=largest(arr,lb,mid); //42
    b=largest(arr,(mid+1),ub);//5
    }
    return max(a,b);
}
int main(){
   int arr[6],i,lb=0,ub=5;
   printf("enter the numbers in a array");
   for(i=0;i<5;i++){
      scanf("%d ",&arr[i]);
   }

   while(lb<ub){
     mid=(lb+ub)/2;
     
   }

  int c=largest(arr,0,5);
  printf("%d ",c);
}