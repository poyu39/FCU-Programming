#include <stdio.h>

#define INPUT_SIZE 10000
#define INPUT_MAX 65536

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
    int dream_num = 0;
    while (scanf("%d", &dream_num) != EOF) {
        if (dream_num == 0) break;
        int dream[INPUT_SIZE];
        for (int i = 0; i < dream_num; i++) {
            scanf("%d", &dream[i]);
        }
        sort(dream, dream_num);
        int median = dream[dream_num / 2];
        int second_median = 0;
        
        int possible = 1;
        if (dream_num % 2 != 0) {
            possible++;
            second_median = dream[dream_num / 2 + 1];
        }
        
        int median_count = 0;
        for (int i = 0; i < dream_num; i++) {
            if (dream[i] == median) {
                median_count++;
            }
        }

        if (possible == 2) {
            possible += second_median - median - 1;
        }

        printf("%d %d %d\n", median, median_count, possible);
    }
}