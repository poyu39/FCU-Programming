#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_word(char *word) {
    for (int i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }
    return 1;
}

int count_word(char *input) {
    int count = 0;
    int input_length = strlen(input);
    char *token;
    const char s[] = " .,;:!?()#/<>';[]{}-_=+*^%$#@&`~|0123456789\"\'\n\t";
    token = strtok(input, s);
    while(token != NULL) {
        if (is_word(token)) {
            count++;
            printf("%s\n", token);
        }
        token = strtok(NULL, s);
    }
    return count;
}

int main() {
    FILE *input_file, *output_file;
    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");

    char input[1000];

    while(fgets(input, 1000, input_file) != NULL) {
        int word_count = count_word(input);
        fprintf(output_file, "%d\n", word_count);
        printf("\n");
    }
}