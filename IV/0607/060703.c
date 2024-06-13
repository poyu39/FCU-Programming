#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_MAX 10000


void *get_primes(int n, int *primes) {
    for (int i = 0; i < n; i++) {
        primes[i] = 1;
    }
    primes[0] = 0;
    primes[1] = 0;
    for (int i = 2; i < n; i++) {
        if (primes[i] == 1) {
            for (int j = i * i; j < n; j += i) {
                primes[j] = 0;
            }
        }
    }
}


int main() {
    int *primes = (int *)malloc(INPUT_MAX * sizeof(int));
    get_primes(INPUT_MAX, primes);
    int min, max = 0;
    while (1) {
        int cprimes = 0;
        scanf("%d", &min);
        if (min == -1) break;
        scanf("%d", &max);
        for (int i = min; i <= max; i++) {
            if (primes[i] == 0) continue;
            int count_digits = 0;
            int temp = i;
            while (temp != 0) {
                temp /= 10;
                count_digits++;
            }
            temp = i;
            int count = 0;
            for (int j = 0; j < count_digits; j++) {
                int shift_num = temp / pow(10, count_digits - 1);
                temp = (temp - shift_num * pow(10, count_digits - 1)) * 10 + shift_num;
                if (primes[temp]) count++;
                if (count == count_digits) cprimes++;
            }
        }
        if (cprimes) {
            if (cprimes == 1) {
                printf("%d Circular Prime.\n", cprimes);
            } else {
                printf("%d Circular Primes.\n", cprimes);
            }
        } else {
            printf("No Circular Primes.\n");
        }
    }
}