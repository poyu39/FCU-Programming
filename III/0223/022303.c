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
    int arr[3];
    while (1) {
        scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
        if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) break;
        sort(arr, 3);
        printf("%d %d %d\n", arr[0], arr[1], arr[2]);
    }
}