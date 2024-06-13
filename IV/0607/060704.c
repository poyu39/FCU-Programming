#include <stdio.h>


int main() {
    char buffer = ' ';
    long long int num = 0;
    while (buffer = getchar()) {
        if (buffer == EOF) break;
        if (buffer == '0' || buffer == '1') {
            num = num * 2 + buffer - '0';
            if (num >= 131071) num -= 131071;
        } else if (buffer == '#') {
            printf("%s\n", num % 131071 == 0 ? "YES" : "NO");
            num = 0;
        }
    }
}