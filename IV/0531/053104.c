#include <stdio.h>


int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int m = 0;
        int f = 0;
        char buffer[3] = "";
        while (scanf("%s", buffer) != EOF) {
            if (buffer[0] == 'M') m++;
            if (buffer[1] == 'F') f++;
            if (getchar() == '\n') break;
        }
        printf("%d , %d", m, f);
        // printf("%s\n", m == f && m > 1 ? "LOOP" : "NO LOOP");
    }
}