#include <stdio.h>

/*
    7                   .
    6                   .
    5   .               .   .
    4   .       .       .   .   _average
    3   .       .       .   .
    2   .   .   .       .   .
    1   .   .   .   .   .   .
*/

// 找到最少的步數，讓每個高度都一樣

int get_average(int* arr, int len) {
    int *ptr_arr = arr;
    int *ptr_len = &len;
    int sum = 0;
    int *ptr_sum = &sum;
    for (int i = 0; i < *ptr_len; i++) {
        *ptr_sum += *(ptr_arr + i);
    }
    int average = *ptr_sum / *ptr_len;
    int *ptr_average = &average;
    int steps = 0;
    int *ptr_steps = &steps;

    // 每個高度要加或減多少才能變成平均值。
    for (int i = 0; i < *ptr_len; i++) {
        if (*(ptr_arr + i) < *ptr_average) {
            *ptr_steps += *ptr_average - *(ptr_arr + i);
        }
    }
    return *ptr_steps;
}

int main() {
    int n;
    int *ptr_n = &n;
    int counter = 0;
    int *ptr_counter = &counter;
    while (scanf("%d", ptr_n) != EOF) {
        if (*ptr_n == 0) {
            break;
        }
        int heights[*ptr_n];
        int *ptr_heights = heights;
        for (int i = 0; i < *ptr_n; i++) {
            scanf("%d", ptr_heights + i);
        }
        (*ptr_counter)++;
        printf("Set #%d\n", *ptr_counter);
        printf("The minimum number of moves is %d.\n\n", get_average(ptr_heights, *ptr_n));
    }
}