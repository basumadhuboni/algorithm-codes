#include <stdio.h>

// Function to count occurrences of a target element in a range of the array
int countInRange(int arr[], int target, int left, int right) {
    int count = 0;
    for (int i = left; i <= right; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    return count;
}

// Function to find the majority element in a range of the array
int findMajorityInRange(int arr[], int left, int right) {
    // Base case: If the range has only one element, return that element
    if (left == right) {
        return arr[left];
    }

    // Divide the range into two halves
    int mid = (left + right) / 2;

    // Recursively find majority elements in the left and right halves
    int left_majority = findMajorityInRange(arr, left, mid);
    int right_majority = findMajorityInRange(arr, mid + 1, right);

    // Count occurrences of the left and right majority elements
    int left_count = countInRange(arr, left_majority, left, right);
    int right_count = countInRange(arr, right_majority, left, right);

    // Return the element with the higher count as the majority element
    if (left_count > (right - left + 1) / 2) {
        return left_majority;
    } else if (right_count > (right - left + 1) / 2) {
        return right_majority;
    } else {
        return -1; // No majority element
    }
}

// Function to find the majority element in the entire array
int findMajority(int arr[], int n) {
    return findMajorityInRange(arr, 0, n - 1);
}

int main() {
    int arr[] = {7,7,6,8,9,7,7,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = findMajority(arr, n);

    if (result != -1) {
        printf("Majority Element: %d\n", result);
    } else {
        printf("No majority element\n");
    }

    return 0;
}