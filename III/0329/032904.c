#include <stdio.h>
#include <string.h>
#include <ctype.h>

void decode(char *input, char *result) {
    int number = 0;
    int result_length = 0;
    for(int i = 0; i < strlen(input); i++) {
        if(isdigit(input[i])) {
            number += input[i] - '0';
        } else {
            for(int j = 0; j < number; j++) {
                result[result_length] = input[i];
                result_length++;
            }
            number = 0;
        }
    }

    // replace all 'b' with ' '
    for(int i = 0; i < strlen(result); i++) {
        if(result[i] == 'b') {
            result[i] = ' ';
        }
    }
}

int main() {
    FILE *input_file, *output_file;
    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");
    char input[133];
    while(fgets(input, 133, input_file) != NULL) {
        char *token;
        const char s[] = "!";
        token = strtok(input, s);
        while(token != NULL) {
            char result[133] = "";
            decode(token, result);
            printf("%s\n", result);
            fprintf(output_file, "%s\n", result);
            token = strtok(NULL, s);
        }
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}