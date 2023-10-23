#include <stdio.h>
int n;
int max(int a, int b,int c){
     int m=a>b?(a>c?a:c):(b>c?b:c);
    return m;
}
int cross_subarray(int arr[],int left,int mid,int right){
    int prol=1,pro_maxl=1,i;
     for(i=mid;i>=left;i--){
         prol=prol*arr[i];
         if(prol>pro_maxl){
            pro_maxl=prol;
         }
     }
     int pror=1,pro_maxr=1;
     for(i=(mid+1);i<=right;i++){
         pror=pror*arr[i];
         if(pror>pro_maxr){
            pro_maxr=pror;
         }
     }
     return (pro_maxl*pro_maxr);
}
int maxproduct(int arr[], int left, int right) {
    if (left == right) {
        return arr[left]; // we are left with just one element 
    }
    
    int mid = (left+right )/ 2;
    int leftpro=maxproduct(arr,left,mid);
    printf("LSS is: %d\n",leftpro);
    int rightpro=maxproduct(arr,mid+1,right);
    printf("RSS is: %d\n",rightpro);
    int cross=cross_subarray(arr,left,mid,right);    
     printf("cSS is: %d\n",cross);

    return max(leftpro,rightpro,cross);
}

int main() {
    int i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int b=maxproduct(arr, 0, (n - 1));
    printf("maximum product of sub array is: %d", b);  
    return 0;
}