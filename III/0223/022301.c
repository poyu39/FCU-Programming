#include <stdio.h>

int fun(int n) {
    if (n % 2 == 0) {
        return n * 2;
    } else {
        return n * n;
    }
}

int main() {
    int n = 1;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        printf("%d\n", fun(n));
    }
}