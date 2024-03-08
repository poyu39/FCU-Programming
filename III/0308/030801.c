#include <stdio.h>

void get_even_total(char* codes, int* total) {
    int this_even_index_num;
    for (int i = 0; i < 16; i++) {
        if (i % 2 == 0) {
            this_even_index_num = (codes[i] - '0') * 2;
            if (this_even_index_num >= 10) {
                this_even_index_num = this_even_index_num / 10 + this_even_index_num % 10;
            }
            *total += this_even_index_num;
        }
    }
}

void get_odd_total(char* codes, int* total) {
    int this_odd_index_num;
    for (int i = 0; i < 16; i++) {
        if (i % 2 == 1) {
            this_odd_index_num = codes[i] - '0';
            *total += this_odd_index_num;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char codes[17] = "                ";
        int even_total = 0, odd_total = 0;
        int total = 0;

        // merge input into one line
        for (int j = 0; j < 4; j++) {
            scanf("%s", codes + j * 4);
        }
        get_even_total(codes, &even_total);
        get_odd_total(codes, &odd_total);
        total = even_total + odd_total;
        if (total % 10 == 0) {
            printf("Valid\n");
        } else {
            printf("Invalid\n");
        }
    }
}