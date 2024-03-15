#include <stdio.h>
#include <stdlib.h>

void sort(int* arr, int len) {
    int *ptr_arr = arr;
    int *ptr_len = &len;
    for (int i = 0; i < *ptr_len; i++) {
        for (int j = 0; j < *ptr_len - i - 1; j++) {
            if (*(ptr_arr + j) > *(ptr_arr + j + 1)) {
                int temp = *(ptr_arr + j);
                *(ptr_arr + j) = *(ptr_arr + j + 1);
                *(ptr_arr + j + 1) = temp;
            }
        }
    }
}

int get_tolal_difference(int* arr, int len) {
    int *ptr_arr = arr;
    int *ptr_len = &len;
    int difference = 0;
    int *ptr_difference = &difference;
    for (int i = 0; i < *ptr_len - 1; i++) {
        *ptr_difference += abs(*(ptr_arr + i) - *(ptr_arr + i + 1));
    }
    return *ptr_difference;
}

int main() {
    int n;
    int *ptr_n = &n;
    scanf("%d", ptr_n);
    
    for(int i = 0; i < *ptr_n; i++) {
        int len;
        int *ptr_len = &len;
        scanf("%d", ptr_len);
        
        int shops[*ptr_len];
        int *ptr_shops = shops;
        for (int j = 0; j < *ptr_len; j++) {
            scanf("%d", ptr_shops + j);
        }

        sort(shops, *ptr_len);
        printf("%d\n", get_tolal_difference(shops, *ptr_len) * 2);
    }
}