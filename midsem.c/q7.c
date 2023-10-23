#include<stdio.h>
#include<stdlib.h>
struct item{
    int value;
    int weight;
};
int main(){
    struct item arr[n];
    int i,p=0,w;
     for(i=0;i<n;i++){
        scanf("%d",&arr[i].value);
        scanf("%d",&arr[i].weight);
     }
     printf("enter max weight");
     scanf("%d",&w);
     i=0;
     while(i<3 && w>arr[i].weight){
        p=p+arr[i].value;
        w=w-arr[i].weight;
        i++;
        printf("%d\n ",p);
     }
     if(i<3){
        p=p+((arr[i].value/arr[i].weight)*w);
     }
     printf("%d",p);
}

