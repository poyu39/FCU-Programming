#include <stdio.h>

void quick_sort(int* arr, int left, int right) {
    int *ptr_arr = arr;
    int *ptr_left = &left;
    int *ptr_right = &right;
    if (*ptr_left < *ptr_right) {
        int pivot = *(ptr_arr + *ptr_right);
        int i = *ptr_left - 1;
        for (int j = *ptr_left; j < *ptr_right; j++) {
            if (*(ptr_arr + j) < pivot) {
                i++;
                int temp = *(ptr_arr + i);
                *(ptr_arr + i) = *(ptr_arr + j);
                *(ptr_arr + j) = temp;
            }
        }
        int temp = *(ptr_arr + i + 1);
        *(ptr_arr + i + 1) = *(ptr_arr + *ptr_right);
        *(ptr_arr + *ptr_right) = temp;
        quick_sort(ptr_arr, *ptr_left, i);
        quick_sort(ptr_arr, i + 2, *ptr_right);
    }
}

int main() {
    int t = 0;
    int *ptr_t = &t;
    scanf("%d", ptr_t);

    for(int i = 0; i < *ptr_t; i++) {
        int len = 0;
        int *ptr_len = &len;
        scanf("%d", ptr_len);
        int items_price[*ptr_len];
        int *ptr_items_price = items_price;
        for (int j = 0; j < *ptr_len; j++) {
            scanf("%d", ptr_items_price + j);
        }
        quick_sort(ptr_items_price, 0, *ptr_len - 1);
        long long int total_discount = 0;
        long long int *ptr_total_discount = &total_discount;
        for (int j = *ptr_len - 3; j >= 0; j -= 3) {
            *ptr_total_discount += *(ptr_items_price + j);
        }
        printf("%lld\n", *ptr_total_discount);
    }
    return 0;
}