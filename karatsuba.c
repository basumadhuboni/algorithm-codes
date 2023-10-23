#include <stdio.h>
#include <string.h>

int makeEqualLength(char str1[], char str2[]) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 < len2) {
        for (int i = 0; i < len2 - len1; i++)
            str1[i] = '0';
        str1[len2 - len1] = '\0';
        return len2;
    }
    else if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++)
            str2[i] = '0';
        str2[len1 - len2] = '\0';
    }
    return len1;
}

char* addBitStrings(char first[], char second[]) {
    int length = makeEqualLength(first, second);
    int carry = 0;

    static char result[1000];
    result[0] = '\0';

    for (int i = length - 1; i >= 0; i--) {
        int firstBit = first[i] - '0';
        int secondBit = second[i] - '0';

        int sum = (firstBit ^ secondBit ^ carry) + '0';

        int temp[2] = { sum, '\0' };
        strcat(result, (char*)temp);

        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }

    if (carry) {
        int temp[2] = { '1', '\0' };
        strcat(result, (char*)temp);
    }

    int len = strlen(result);
    for (int i = len - 1; i >= len / 2; i--) {
        char temp = result[i];
        result[i] = result[len - i - 1];
        result[len - i - 1] = temp;
    }

    return result;
}

int multiplyiSingleBit(char a, char b) {
    return (a - '0') * (b - '0');
}

long int multiply(char X[], char Y[]) {
    int n = makeEqualLength(X, Y);

    if (n == 0) return 0;
    if (n == 1) return multiplyiSingleBit(X[0], Y[0]);

    int fh = n / 2;
    int sh = (n - fh);

    char Xl[1000], Xr[1000], Yl[1000], Yr[1000];
    strncpy(Xl, X, fh);
    Xl[fh] = '\0';
    strcpy(Xr, X + fh);
    strncpy(Yl, Y, fh);
    Yl[fh] = '\0';
    strcpy(Yr, Y + fh);

    long int P1 = multiply(Xl, Yl);
    long int P2 = multiply(Xr, Yr);
    long int P3 = multiply(addBitStrings(Xl, Xr), addBitStrings(Yl, Yr));

    return P1 * (1 << (2 * sh)) + (P3 - P1 - P2) * (1 << sh) + P2;
}

int main() {
    printf("%ld\n", multiply("1100", "1010"));
    printf("%ld\n", multiply("110", "1010"));
    printf("%ld\n", multiply("11", "1010"));
    printf("%ld\n", multiply("1", "1010"));
    printf("%ld\n", multiply("0", "1010"));
    printf("%ld\n", multiply("111", "111"));
    printf("%ld\n", multiply("11", "11"));

    return 0;
}