#include<stdio.h>

int brute_force(int r){
    int a=-1,b=1,t=0,c;
    while(t<=r){
       c=a+b;
       a=b;
       b=c;
       t++;
    }
    return c;
}
int topdown(int r){
    if(r==2){ // 2nd term is 1
        return 1;
    }
    if(r==1){ // first term is 0
        return 0;
    }

    return (topdown(r-1)+topdown(r-2));
}
int bottomup(int r){
    int arr[r+1],i;
    arr[0]=0,arr[1]=1;
    for(i=2;i<=r;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    return arr[r];
}
int bottomupconst(int r){
    int a=-1,b=1,c,i;
    for(i=1;i<(r+1);i++){
       c=a+b;
       a=b;
       b=c;
    }
    return c;
}
int main(){
    int k;
   printf("enter the rank of the fibonacci number u want");
   scanf("%d",&k);
   int n=brute_force(k);
   printf("the k th fibonacci number %d ",n);
   n=topdown(k);
   printf("the k th fibonacci number %d ",n);
   n=bottomup(k);
   printf("the k th fibonacci number %d ",n);
   n=bottomupconst(k);
   printf("the k th fibonacci number %d ",n);
}