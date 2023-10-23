#include <stdio.h>
int n;

int find_missing_number(int nums[], int left, int right) {
    if (left == right) {
        return left + 1; // we are left with just one element 
    }
    
    int mid = left + (right - left) / 2;
    
    if (nums[mid] == mid + 1) {
        // The missing number is in the right half
        return find_missing_number(nums, mid + 1, right);
    } else {
        // The missing number is in the left half
        return find_missing_number(nums, left, mid);
    }
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
    int b=find_missing_number(arr, 0, (n - 1));
    printf("missing element is: %d", b);  
    return 0;
}