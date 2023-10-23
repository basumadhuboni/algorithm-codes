#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insertion_sort(int arr[], int lb, int ub) {
    int i, key, j;
    for (i = lb; i <= ub; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= lb && key < arr[j]) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}

int find_median(int arr[], int lb, int ub) {
    insertion_sort(arr, lb, ub);
    printf("array after sorting is ");
    for(int i=lb;i<=ub;i++){
        printf("%d ",arr[i]);
    }
    printf("\n ");
    int pos = lb + ((ub - lb) / 2);
    return arr[pos];
}

int partition(int arr[], int lb, int ub) {
    int j, i = lb - 1, pivot = arr[ub];
    for (j = lb; j <= ub; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[ub]);
    return (i + 1);
}

int select_linear(int arr[], int lb, int ub, int k2) {
    int n = ub - lb + 1, posofmed, nogroup, rankofmed, i, j, ng;
    if (n <= 5) {
        insertion_sort(arr, lb, ub);

        if(n%2==0){
          return arr[ (n/2)+1 ];
        }
        else{
            return arr[n/2];
        }
    }
    nogroup = n / 5;
    if(nogroup%5==0){
        ng=nogroup;
    }
    else{
        ng=nogroup+1;
    }
    printf("no of groups is %d ",ng);

    int medians[ng];
    int start = lb;
    for (i = 0; i < nogroup; i++) {
        printf("start = %d \n",start);
        medians[i] = find_median(arr, start, start + 4);
        printf("%d ",medians[i]);
        start = start + 5;
    }

    medians[nogroup-1]=find_median(arr,start,ub);
    printf("%d %d \n",medians[0],medians[1]);
    int medofmed = select_linear(medians, 0, nogroup - 1, (nogroup / 2));
    printf(" median of median is %d \n",medofmed);
    for (i = lb; i <= ub; i++) {
        if (arr[i] == medofmed) {
            posofmed = i;
            break;
        }
    }
    swap(&arr[ub], &arr[posofmed]);
    posofmed = partition(arr, lb, ub);
    rankofmed = posofmed - lb + 1;
    if (rankofmed == k2) {
        return arr[posofmed];
    } else if (rankofmed < k2) {
        return select_linear(arr, posofmed + 1, ub, k2 - rankofmed);
    } else {
        return select_linear(arr, lb, posofmed - 1, k2);
    }
}

int main() {
    int n, i, k;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n");
    printf("Enter the value of k: ");
    scanf("%d", &k);
    int lb = 0;
    int ub = n - 1;
    int k1 = select_linear(arr, lb, ub, k);
    printf("The %dth smallest element is %d\n", k, k1);

    return 0;
}