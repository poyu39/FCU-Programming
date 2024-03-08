#include <stdio.h>

void sort(int* arr, int len) {

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n = 0, r = 0;
    int *ptr_n = &n, *ptr_r = &r;
    while (scanf("%d %d", ptr_n, ptr_r) != EOF) {
        int survivors[*ptr_n];
        int all_id[*ptr_n];
        for (int i = 0; i < *ptr_r; i++) {
            scanf("%d", &survivors[i]);
        }
        for (int i = 0; i < *ptr_n; i++) {
            all_id[i] = i + 1;
        }

        for (int i = 0; i < *ptr_r; i++) {
            for (int j = 0; j < *ptr_n; j++) {
                if (survivors[i] == all_id[j]) {
                    all_id[j] = 0;
                }
            }
        }
        sort(all_id, *ptr_n);
        
        int all_survive = 1;
        for (int i = 0; i < *ptr_n; i++) {
            if (all_id[i] != 0) {
                printf("%d ", all_id[i]);
                all_survive = 0;
            }
        }
        if (all_survive) {
            printf("*");
        }
        printf("\n");
    }
    
}