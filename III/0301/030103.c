#include <stdio.h>

int main() {
    int a, b, diff;
    int *ptr_a = &a, *ptr_b = &b, *ptr_diff = &diff;
    while (1) {
        scanf("%d %d", ptr_a, ptr_b);
        if (*ptr_a == -1 && *ptr_b == -1) break;
        *ptr_diff = *ptr_a - *ptr_b;
        if (*ptr_diff < 0) *ptr_diff = -*ptr_diff;
        if (*ptr_diff > 50) *ptr_diff = 100 - *ptr_diff;
        printf("%d\n", *ptr_diff);
    }
}