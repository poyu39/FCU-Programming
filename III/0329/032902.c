#include <stdio.h>
#include <string.h>

// Run-Length Decoding。
void cut_input(char *input, char *result) {
    int input_length = strlen(input);
    int str_length = 0;
    for(int i = 0; i < input_length; i++) {
        char letter = input[i];
        int number = 0;
        for(int j = i + 1; i < input_length; j++) {
            if(input[j] >= '0' && input[j] <= '9') {
                number = number * 10 + (input[j] - '0');
            } else {
                i = j - 1;
                break;
            }
        }
        for(int j = 0; j < number; j++) {
            result[str_length + j] = letter;
        }
        str_length += number;
    }
    result[str_length] = '\0';
}

int main() {
    FILE *input_file, *output_file;
    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");
    int t;
    fscanf(input_file, "%d", &t);
    int case_count = 1;
    char input[200];
    for(int i = 0; i < t; i++) {
        fscanf(input_file, "%s", input);
        char result[200] = "";
        cut_input(input, result);
        fprintf(output_file, "Case %d: %s\n", case_count, result);
        case_count++;
    }
    return 0;
}