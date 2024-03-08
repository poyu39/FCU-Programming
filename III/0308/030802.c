#include <stdio.h>

/*
    每歸還3個空瓶，可換取一瓶巧克力口味可樂
    可以借x瓶可樂，但是借來的空瓶也要歸還
    最多可以喝到幾瓶可樂
*/


int main() {
    int n;
    int *ptr_n = &n;
    while (scanf("%d", ptr_n) != EOF) {
        int sum = 0;
        int *ptr_sum = &sum;
        int start_bottle = *ptr_n;
        int *ptr_start_bottle = &start_bottle;
        while (*ptr_n >= 3) {
            *ptr_sum += *ptr_n / 3;
            *ptr_n = *ptr_n / 3 + *ptr_n % 3;
        }
        if (*ptr_n == 2) {
            *ptr_sum += 1;
        }
        // *ptr_sum += *ptr_start_bottle;
        printf("%d\n", *ptr_sum);
    }
}