#include <stdio.h>

int main() {
    int size;
    int *ptr_size = &size;
    
    int counter = 0;
    int *ptr_counter = &counter;

    while (scanf("%d", ptr_size) != EOF) {
        int arr[*ptr_size];
        int *ptr_arr = arr;
        for (int i = 0; i < *ptr_size; i++) {
            scanf("%d", ptr_arr + i);
        }
        long long int max = *ptr_arr;
        long long int *ptr_max = &max;
        long long int min = *ptr_arr;
        long long int *ptr_min = &min;
        long long int result = *ptr_max;
        long long int *ptr_result = &result;
        for (int i = 1; i < *ptr_size; i++) {
            if (*(ptr_arr + i) < 0) {
                long long int temp = *ptr_max;
                *ptr_max = *ptr_min;
                *ptr_min = temp;
            }
            long long int current = *(ptr_arr + i);
            long long int *ptr_current = &current;
            long long int product_max = *ptr_max * current;
            long long int product_min = *ptr_min * current;

            if (*ptr_current > product_max) {
                *ptr_max = *ptr_current;
            } else {
                *ptr_max = product_max;
            }

            if (*ptr_current < product_min) {
                *ptr_min = *ptr_current;
            } else {
                *ptr_min = product_min;
            }

            if (*ptr_result < *ptr_max) {
                *ptr_result = *ptr_max;
            }

            if (*ptr_result < 0) {
                *ptr_result = 0;
            }
            // printf("max: %lld, min: %lld, result: %lld\n", *ptr_max, *ptr_min, *ptr_result);
        }
        (*ptr_counter)++;
        if (*ptr_result < 0) {
            *ptr_result = 0;
        }
        printf("Case #%d: The maximum product is %lld.\n\n", *ptr_counter, *ptr_result);
    }
}