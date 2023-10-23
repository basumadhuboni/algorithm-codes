#include<iostream>
using namespace std;

void merge(int arr[], int lb, int mid1, int mid2, int mid3, int ub) {
    int n1 = mid1 - lb + 1;
    int n2 = mid2 - mid1;
    int n3 = mid3 - mid2;
    int n4 = ub - mid3;

    int t1[n1], t2[n2], t3[n3], t4[n4];
    
    // Copy data to temporary arrays t1, t2, t3, t4
    for (int i = 0; i < n1; i++) {
        t1[i] = arr[lb + i];
    }
    for (int i = 0; i < n2; i++) {
        t2[i] = arr[mid1 + 1 + i];
    }
    for (int i = 0; i < n3; i++) {
        t3[i] = arr[mid2 + 1 + i];
    }
    for (int i = 0; i < n4; i++) {
        t4[i] = arr[mid3 + 1 + i];
    }

    // Merge the four subarrays into the original array
    int i = 0, j = 0, k = 0, r = 0;
    int start = lb;

    while (i < n1 && j < n2 && k < n3 && r < n4) {
        if (t1[i] <= t2[j] && t1[i] <= t3[k] && t1[i] <= t4[r]) {
            arr[start++] = t1[i++];
        } else if (t2[j] <= t1[i] && t2[j] <= t3[k] && t2[j] <= t4[r]) {
            arr[start++] = t2[j++];
        } else if (t3[k] <= t1[i] && t3[k] <= t2[j] && t3[k] <= t4[r]) {
            arr[start++] = t3[k++];
        } else {
            arr[start++] = t4[r++];
        }
    }

    // Copy remaining elements of t1, t2, t3, t4 if any
    while (i < n1) {
        arr[start++] = t1[i++];
    }
    while (j < n2) {
        arr[start++] = t2[j++];
    }
    while (k < n3) {
        arr[start++] = t3[k++];
    }
    while (r < n4) {
        arr[start++] = t4[r++];
    }
}

void mergeSort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int mid1 = lb + (ub - lb) / 4;
        int mid2 = lb + (ub - lb) / 2;
        int mid3 = lb + 3 * (ub - lb) / 4;

        mergeSort(arr, lb, mid1);
        mergeSort(arr, mid1 + 1, mid2);
        mergeSort(arr, mid2 + 1, mid3);
        mergeSort(arr, mid3 + 1, ub);

        merge(arr, lb, mid1, mid2, mid3, ub);
    }
}

int main() {
    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}