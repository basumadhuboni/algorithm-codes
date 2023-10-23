#include <stdio.h>

int main() {
    int t,x,p,m,n;
    scanf("%d",&t);
    while(t>=1){
        scanf("%d ",&x);
        p=x*(20/100);
        m=100%p;
        if(m==0){
            n=m;
        }
        else{
            n=m+1;
        }
        printf("%d\n",n);
        t=t-1;
       
    }
    return 0;
}