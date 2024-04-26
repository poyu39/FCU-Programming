#include <stdio.h>

int main() {
    char num[1000];
    while (scanf("%s", num) != EOF) {
        if (num[0] == '0' && num[1] == '\0') break;
        long long int odd_total = 0;
        long long int even_total = 0;
        for (int i = 0; num[i] != '\0'; i++) {
            if (i % 2 == 0) {
                odd_total += num[i] - '0';
            } else {
                even_total += num[i] - '0';
            }
        }
        if ((odd_total - even_total) % 11 == 0) {
            printf("%s is a multiple of 11.\n", num);
        } else {
            printf("%s is not a multiple of 11.\n", num);
        }
    }
}