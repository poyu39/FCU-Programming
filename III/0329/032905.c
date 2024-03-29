#include <stdio.h>

int main() {
    FILE *input_file, *output_file;
    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");

    int buffer[1024];
    int buffer_index = 0;
    int c;

    while(1) {
        c = fgetc(input_file);
        if (c == EOF) break;
        buffer[buffer_index++] = c;
    }
    for(int i = 0; i < buffer_index * 2; i++) {
        fprintf(output_file, "%c", buffer[i % buffer_index]);
        if (i == buffer_index - 1) fprintf(output_file, "\n");
    }

    fclose(input_file);
    fclose(output_file);
}