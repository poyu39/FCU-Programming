#include <stdio.h>

struct customer {
    char lastName[15];
    char firstName[15];
    double payment;
    unsigned int customerNumber;
};

int main() {
    struct customer c[100];
    int c_len = 0;
    while (scanf("%s %s %lf %u", c[c_len].lastName, c[c_len].firstName, &c[c_len].payment, &c[c_len].customerNumber) != EOF) {
        c_len++;
    }
    int max_payment = 0;
    for (int i = 0; i < c_len; i++) {
        if (c[i].payment > c[max_payment].payment) {
            max_payment = i;
        }
    }
    printf("%s %s %u\n", c[max_payment].lastName, c[max_payment].firstName, c[max_payment].customerNumber);
}