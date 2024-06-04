#include <stdio.h>
#include <stdlib.h>


void sort(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int r = 0;
        scanf("%d", &r);
        int *s = (int *)malloc(r * sizeof(int));
        for (int j = 0; j < r; j++) {
            scanf("%d", &s[j]);
        }
        // 計算差值總和
        sort(s, r);
        int d = 0;
        for (int j = 0; j < r; j++) {
            d += abs(s[r / 2] - s[j]);
        }
        printf("%d\n", d);
    }
}