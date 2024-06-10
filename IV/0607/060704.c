#include <stdio.h>


int main() {
    char buffer[200];
    while (scanf("%s", buffer) != EOF) {
        // bin to dec
        long long int num = 0;
        for (int i = 0; buffer[i] != '#'; i++) {
            num = num * 2 + buffer[i] - '0';
        }
        printf("%s\n", num % 131071 == 0 ? "YES" : "NO");
    }
}