#include <stdio.h>

void get_even_total(char* codes, int* total) {
    int this_even_index_num;
    int *ptr_this_even_index_num = &this_even_index_num;
    for (int i = 0; i < 16; i++) {
        if (i % 2 == 0) {
            *ptr_this_even_index_num = (codes[i] - '0') * 2;
            if (*ptr_this_even_index_num >= 10) {
                *ptr_this_even_index_num = *ptr_this_even_index_num / 10 + *ptr_this_even_index_num % 10;
            }
            *total += *ptr_this_even_index_num;
        }
    }
}

void get_odd_total(char* codes, int* total) {
    int this_odd_index_num;
    int *ptr_this_odd_index_num = &this_odd_index_num;
    for (int i = 0; i < 16; i++) {
        if (i % 2 == 1) {
            *ptr_this_odd_index_num = codes[i] - '0';
            *total += *ptr_this_odd_index_num;
        }
    }
}

int main() {
    int n;
    int *ptr_n = &n;
    scanf("%d", ptr_n);
    for (int i = 0; i < n; i++) {
        char codes[17] = "                ", *ptr_codes = codes;
        int even_total = 0, odd_total = 0, *ptr_even_total = &even_total, *ptr_odd_total = &odd_total;
        int total = 0, *ptr_total = &total;

        // merge input into one line
        for (int j = 0; j < 4; j++) {
            scanf("%s", ptr_codes + j * 4);
        }
        get_even_total(ptr_codes, ptr_even_total);
        get_odd_total(ptr_codes, ptr_odd_total);
        *ptr_total = *ptr_even_total + *ptr_odd_total;
        if (*ptr_total % 10 == 0) {
            printf("Valid\n");
        } else {
            printf("Invalid\n");
        }
    }
}