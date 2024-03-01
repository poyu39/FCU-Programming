#include <stdio.h>

void get_factors(int num, int* factors, int* factors_len) {
    int *ptr_num = &num;
    int *ptr_factors = factors;
    for(int i = 1; i <= *ptr_num; ++ i) {
        if (*ptr_num % i == 0 && i != *ptr_num) {
            *ptr_factors = i;
            ptr_factors++;
            *factors_len += 1;
        }
    }
}

int main() {
    int cases;
    int *ptr_cases = &cases;
    scanf("%d", ptr_cases);
    for (int i = 0; i < cases; i++) {
        int input;
        int *ptr_input = &input;
        scanf("%d", ptr_input);
        
        int factors[input];
        int *ptr_factors = factors;
        int factors_len = 0;
        int *ptr_factors_len = &factors_len;
        get_factors(input, ptr_factors, ptr_factors_len);
        // for (int j = 0; j < factors_len; j++) {
        //     printf("%d ", factors[j]);
        // }
        
        int sum = 0;
        int *ptr_sum = &sum;
        for (int j = 0; j < factors_len; j++) {
            *ptr_sum += factors[j];
        }

        if (*ptr_sum == *ptr_input) {
            printf("perfect\n");
        } else if (*ptr_sum < *ptr_input) {
            printf("deficient\n");
        } else {
            printf("abundant\n");
        }
    }
}