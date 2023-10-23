#include <stdio.h>

int inversion_count(int arr[], int lb, int mid, int ub) {
    int n1 = mid - lb + 1;
    int n2 = ub - mid;
    int ct = 0, i, j, k;
    int left[n1], right[n2];

    // Forming the left subarray
    for (i = 0; i < n1; i++) {
        left[i] = arr[lb + i];
    }

    // Forming the right subarray
    for (j = 0; j < n2; j++) {
        right[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = lb;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else { // Inversion case
            arr[k] = right[j];
            j++;
            ct += (mid-lb - i+1); // Count the number of inversions
        }
        k++;
    }

    // Copy the remaining elements of left and right subarrays
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }

    return ct;
}

int merge_sort_inversion(int arr[], int lb, int ub) {
    int count = 0;
    if (lb < ub) {
        int mid = lb + (ub - lb) / 2;
        count += merge_sort_inversion(arr, lb, mid);
        count += merge_sort_inversion(arr, mid + 1, ub);
        count += inversion_count(arr, lb, mid, ub);
    }
    return count;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int inversions = merge_sort_inversion(arr, 0, n - 1);

    printf("Total number of inversions: %d\n", inversions);

    return 0;
}