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

long long int median(int* arr, int len) {
    long long int sum = 0;
    if (len % 2 == 0) {
        sum = arr[len / 2];
        sum += arr[len / 2 - 1];
        return sum / 2;
    } else {
        return arr[len / 2];
    }
}

int main() {
    int arr[10000];
    int index = 0;
    int input;
    while(scanf("%d",&input) != EOF) {
        arr[index] = input;
        sort(arr, index + 1);
        printf("%lld\n", median(arr, index + 1));
        index++;
    }
}