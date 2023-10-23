#include <stdio.h>

int maxElement(int nums[], int size) {
    int max = nums[0];
    for (int i = 0; i < size; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    return max;
}

int LIS(int nums[], int size) {
    int dp[size];
    for (int i = 0; i < size; i++) {
        dp[i] = 1;
    }

    if (size == 0) {
        return 0;
    } else {
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (1 + dp[j] > dp[i]) {
                        dp[i] = 1 + dp[j];
                    }
                }
            }
        }
        for(int i=0;i<size;i++){
            printf("%d ",dp[i]);
        }
        return maxElement(dp, size);
    }
}

int main() {
    int nums[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int size = sizeof(nums) / sizeof(nums[0]);

    printf("Length of longest increasing subsequence: %d\n", LIS(nums, size));

    return 0;
}