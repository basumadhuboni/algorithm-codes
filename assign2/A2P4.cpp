#include<stdio.h>
#include<limits.h>
int n;
void merge(int arr[], int lb, int mid1, int mid2, int mid3, int ub) {
    int n1=mid1-lb+1,n2=mid2-mid1,n3=mid3-mid2,n4=ub-mid3;
    int t1[n1+1],t2[n2+1],t3[n3+1],t4[n4+1];
    int i=0,j=0,k=0,r=0,start=lb;
    t1[n1]=INT_MAX;
    t2[n2]=INT_MAX;
    t3[n3]=INT_MAX;
    t4[n4]=INT_MAX;
    for(i=0;i<n1;i++){
        t1[i]=arr[start++];
    }
    for(i=0;i<n2;i++){
        t2[i]=arr[start++];
    }
    for(i=0;i<n3;i++){
        t3[i]=arr[start++];
    }
    for(i=0;i<n4;i++){
        t4[i]=arr[start++];
    }
    
    i=0,j=0,k=0,r=0;
    start=lb;
    while(start<=ub){
        if(t1[i]<=t2[j] && t1[i]<=t3[k] && t1[i]<=t4[r]){
            arr[start++]=t1[i++];
        }
        else if(t2[j]<=t1[i] && t2[j]<=t3[k] && t2[j]<=t4[r]){
            arr[start++]=t2[j++];
        }
        else if(t3[k]<=t2[j] && t3[k]<=t1[i] && t3[k]<=t4[r]){
            arr[start++]=t3[k++];
        }
        else if(t4[r]<=t1[i] && t4[r]<=t2[j] && t4[r]<=t3[k]){
            arr[start++]=t4[r++];
        }
    }
    
}

void mergesort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int mid2=lb+((ub-lb)/2);
        int mid1=lb+((mid2-lb)/2);
        int mid3=ub-((ub-mid2)/2);
        mergesort(arr, lb, mid1);
        mergesort(arr, mid1 + 1, mid2);
        mergesort(arr, mid2 + 1, mid3);
        mergesort(arr, mid3 + 1, ub);
        merge(arr, lb, mid1, mid2, mid3, ub);
    }
}

int main() {
    int i;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, n - 1);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}