#include <stdio.h>
int n,smax=0;

int majority(int arr[],int left,int right){
    int mid=(left+right)/2;
    int s=0,i,a;
    
    for(i=left;i<=right;i++){
        if(arr[mid]==arr[i]){
            s=s+1;
        }
    }
    if(s>smax){
        smax=s;
    }
    if(smax>(n/2)){
        return arr[mid];
    }
        a=majority(arr,left,mid);
       a= majority(arr,mid+1,right);
       return a;
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
    int b=majority(arr, 0, (n - 1));
    printf("majority number is: %d",b);  
    return 0;
}