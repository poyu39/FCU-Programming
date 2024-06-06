#include <stdio.h>


int count_c(char target, char *buffer) {
    int count = 0;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == target) {
            count++;
        }
    }
    return count;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int m = 0;
        int f = 0;
        char buffer[3] = "";
        while (scanf("%s", buffer) != EOF) {
            m += count_c('M', buffer);
            f += count_c('F', buffer);
            if (getchar() == '\n') break;
        }
        // printf("%d , %d\n", m, f);
        printf("%s\n", m == f && m > 1? "LOOP" : "NO LOOP");
    }
}