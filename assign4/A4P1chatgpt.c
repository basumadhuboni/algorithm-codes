#include <stdio.h>

int find_peak_element(int arr[], int left, int right) {
    if (left == right) {
        return left;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] >= arr[mid + 1]) {
        // If the middle element is greater than or equal to its right neighbor, a peak might exist in the left half
        return find_peak_element(arr, left, mid);
    } else {
        // If the middle element is less than its right neighbor, a peak might exist in the right half
        return find_peak_element(arr, mid + 1, right);
    }
}

int main() {
    int arr[] = {0, 8, 3, 5, 7, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int peak_index = find_peak_element(arr, 0, n - 1);
    printf("A peak element is at index %d with value %d\n", peak_index, arr[peak_index]);

    return 0;
}