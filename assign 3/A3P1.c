#include <stdio.h>
int a; // we are making the maximum value global
struct value{
    int ma;
    int mi;
}result;
int max(int x, int y){
    if(x > y){
        return x;
    }else{
        return y;
    }
}
int min(int x, int y){
    if(x < y){
        return x;
    }else{
        return y;
    }
}
struct value findmaxmin(int arr[], int lb, int ub) {
    struct value localResult;  // Create a local struct value
    
    if (lb == ub) {
        localResult.ma = arr[lb];
        localResult.mi = arr[lb];
        return localResult;  // Return the local struct value
    }
    
    int mid = (lb + ub) / 2;
    struct value leftResult = findmaxmin(arr, lb, mid);
    struct value rightResult = findmaxmin(arr, mid + 1, ub);
    
    localResult.ma = max(leftResult.ma, rightResult.ma);
    localResult.mi = min(leftResult.mi, rightResult.mi);
    
    return localResult;  // Return the local struct value
}
int findmax(int arr[], int lb, int ub) {
    int m1,m2;
    
    if(lb==ub){
        return(arr[lb]);
    }
        int mid = (lb + ub) / 2;
        //sorting the subarrays
       m1=findmax(arr, lb, mid);
        m2=findmax(arr, mid + 1, ub);
    return max(m1,m2);
}
int findmin(int arr[], int lb, int ub) {
    int m1,m2;
    
     if(lb==ub){
        return(arr[lb]);
    }
        int mid = (lb + ub) / 2;
        //sorting the subarrays
       m1=findmin(arr, lb, mid);
        m2=findmin(arr, mid + 1, ub);
    return min(m1,m2);
}
int secondlargest(int arr[],int lb,int ub){
    int m1,m2;
    
    if(lb==ub){
        if(arr[lb]!=a){
           return 0;
        }
        else{
            return min(a,arr[lb]);
        }
    }
        int mid = (lb + ub) / 2;
        //sorting the subarrays
       m1=secondlargest(arr, lb, mid);
        m2=secondlargest(arr, mid + 1, ub);
    return max(m1,m2);
}

int main() {
    int n,k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
     a=findmax(arr, 0, n - 1); // we are making the max global
    printf("max element is: %d \n",a);
    int b=findmin(arr, 0, n - 1);
    printf("min element is: %d \n",b);
    result=findmaxmin(arr, 0, n - 1);
    printf("max element is: %d \n",result.ma);
    printf("min element is: %d \n",result.mi);
    int c=secondlargest(arr, 0, n - 1);
     printf("second largest element is: %d \n",c);
}