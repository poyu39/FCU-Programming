#include <stdio.h>

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

int main() {
    int n = 0, r = 0;
    int *ptr_n = &n, *ptr_r = &r;
    while (scanf("%d %d", ptr_n, ptr_r) != EOF) {
        int survivors[*ptr_n];
        int *ptr_survivors = survivors;
        int all_id[*ptr_n];
        int *ptr_all_id = all_id;
        for (int i = 0; i < *ptr_r; i++) {
            scanf("%d", ptr_survivors + i);
        }
        for (int i = 0; i < *ptr_n; i++) {
            *(ptr_all_id + i) = i + 1;
        }

        for (int i = 0; i < *ptr_r; i++) {
            for (int j = 0; j < *ptr_n; j++) {
                if (*(ptr_survivors + i) == *(ptr_all_id + j)) {
                    *(ptr_all_id + j) = 0;
                }
            }
        }
        sort(ptr_all_id, *ptr_n);
        
        int all_survive = 1;
        int *ptr_all_survive = &all_survive;
        for (int i = 0; i < *ptr_n; i++) {
            if (*(ptr_all_id + i) != 0) {
                printf("%d ", *(ptr_all_id + i));
                *ptr_all_survive = 0;
            }
        }
        if (*ptr_all_survive) {
            printf("*");
        }
        printf("\n");
    }
    
}