#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *input_file, *output_file;
    int number;
    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");
    while (fscanf(input_file, "%d", &number) == 1) {
        int square = number * number;
        fprintf(output_file, "%d ", square);
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}