#include <stdio.h>
#include <string.h>

int main() {
    FILE *input_file, *output_file;
    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");

    int case_num;
    fscanf(input_file, "%d\n", &case_num);

    for (int c = 0; c < case_num; c++) {
        int len;
        fscanf(input_file, "%d\n", &len);
        int A[1000], B[1000];
        for (int j = 0; j < len; j++) {
            fscanf(input_file, "%d", &A[j]);
        }
        int smaller = 0;
        for (int j = 1; j < len; j++) {
            for (int k = 0; k < j; k++) {
                if (A[k] <= A[j]) {
                    smaller++;
                }
            }
            B[j] = smaller;
        }
        ;
        fprintf(output_file, "%d\n", smaller);
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}