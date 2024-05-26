#include <stdio.h>
#include <stdlib.h>

#define INPUT_SIZE 1000000
#define INPUT_MAX 65536

void sort(int *arr, int len) {
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

void find_median(int *arr, int len, int *m1, int *m2) {
    if (len % 2 == 0) {
        *m1 = arr[len / 2 - 1];
        *m2 = arr[len / 2];
    } else {
        *m1 = arr[len / 2];
        *m2 = *m1;
    }
}

void count_median(int *arr, int len, int m1, int m2) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] == m1 || arr[i] == m2) {
            count++;
        }
    }
    if (m2 == INPUT_MAX + 1)
        printf("%d %d %d\n", m1, count, 1);
    else
        printf("%d %d %d\n", m1, count, abs(m1 - m2) + 1);
}

int main() {
    int dream_num = 0;
    while (scanf("%d", &dream_num) != EOF) {
        if (dream_num == 0) break;
        int *dream = (int *)malloc(INPUT_SIZE * sizeof(int));
        for (int i = 0; i < dream_num; i++) {
            scanf("%d", &dream[i]);
        }
        sort(dream, dream_num);
        int m1 = 0, m2 = 0;
        find_median(dream, dream_num, &m1, &m2);
        count_median(dream, dream_num, m1, m2);
        free(dream);
    }
    return 0;
}