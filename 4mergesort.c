//Merge sorting with 4 sub problems

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void merge(int arr[],int low,int high,int mid1,int mid2,int mid3){
    int n1=mid1-low+1;
    int n2=mid2-mid1;
    int n3=mid3-mid2;
    int n4=high-mid3;
    int arr1[n1+1];
    int arr2[n2+1];
    int arr3[n3+1];
    int arr4[n4+1];
    //setting last elemnt of the sub arrays equal to the largest possible integer value
    arr1[n1]=INT_MAX;
    arr2[n2]=INT_MAX;
    arr3[n3]=INT_MAX;
    arr4[n4]=INT_MAX;
    for(int i=0;i<n1;i++){
        arr1[i]=arr[low+i];
    }
    for(int i=0;i<n2;i++){
        arr2[i]=arr[mid1+1+i];
    }
    for(int i=0;i<n3;i++){
        arr3[i]=arr[mid2+1+i];
    }
    for(int i=0;i<n4;i++){
        arr4[i]=arr[mid3+i+1];
    }
    int i=0;
    int j=0;
    int k=0;
    int l=0;
    int start=low;
    while(start<=high){
        if(arr1[i]<=arr2[j] && arr1[i]<=arr3[k] && arr1[i]<=arr4[l]){
            arr[start]=arr1[i];
            i++;
            start++;
        }else if(arr2[j]<=arr1[i] && arr2[j]<=arr3[k] && arr2[j]<=arr4[l]){
            arr[start]=arr2[j];
            j++;
            start++;
        }else if(arr3[k]<=arr2[j] && arr3[k]<=arr1[i] && arr3[k]<=arr4[l]){
            arr[start]=arr3[k];
            k++;
            start++;
        }else{
            arr[start]=arr4[l];
            l++;
            start++;
        }
    }
}

void mergeSort(int arr[],int low,int high){
    if(low<high){
        int mid2=low+(high-low)/2;
        int mid1=low+(mid2-low)/2;
        int mid3=mid2+(high-mid2)/2;
        mergeSort(arr,low,mid1);
        mergeSort(arr,mid1+1,mid2);
        mergeSort(arr,mid2+1,mid3);
        mergeSort(arr,mid3+1,high);
        merge(arr,low,high,mid1,mid2,mid3);
    }
}

int main(){
    int n;
    printf("Please enter the number of elements you want to enter in the array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Please enter the elements of the array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("The initial array was\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    mergeSort(arr,0,n-1);
    printf("\nThe final array formed after performing merge sort on 4 sub problems is \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}