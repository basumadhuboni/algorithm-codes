#include <stdio.h>
int n;
int peak_element(int arr[], int left, int right) {
    int m;
     if(left==right){
          if(left==0 && arr[left+1]>=arr[left]){
            return left;
              }
         else if(left==(n-1) && arr[left]>=arr[left-1]){
            return arr[left];
            }
          else if(left!=0 && left!=(n-1) && arr[left]>=arr[left-1] && arr[left]>=arr[left+1]){
               return arr[left];
            }
            else{
                 return 0;
            }
      }
    
    int mid=(left+right)/2;
    m=peak_element(arr,left,mid);
    if(m==0){
       m=peak_element(arr,(mid+1),right);
    }
    else if(m!=0){
       return m;
    }
    return m;
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
    int b=peak_element(arr, 0, (n - 1));
    printf("peak element is: %d", b);  
    return 0;
}