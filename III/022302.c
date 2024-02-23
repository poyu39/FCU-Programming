#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a, b;
    while (1) {
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0) break;
        swap(&a, &b);
        printf("%d %d\n", a, b);
    }
}