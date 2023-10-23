#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int lis(char str[], int n) {
    int lis[n];
    int max_length = 1;

    lis[0] = 1;

    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++) {
            if (str[i] > str[j]) {
                lis[i] = max(lis[i], lis[j] + 1);
                max_length = max(max_length, lis[i]);
            }
        }
    }

    return max_length;
}

int main() {
    char str[] = "abdcefgi";
    int n = sizeof(str) / sizeof(str[0]) - 1; // Subtract 1 for null terminator

    int length = lis(str, n);

    printf("Length of Longest Increasing Substring: %d\n", length);

    return 0;
}