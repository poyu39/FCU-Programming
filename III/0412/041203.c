#include <stdio.h>
#include <string.h>

void reverse(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

int main() {
    FILE *input_file, *output_file;
    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");

    char buffer[200];

    while (fgets(buffer, 200, input_file) != NULL) {
        int g;
        char s[200];
        sscanf(buffer, "%d %s\n", &g, s);
        if (g == 0) break;
        int group_len = strlen(s) / g;

        for (int i = 0; i < g; i++) {
            char s_temp[200];
            for (int j = 0; j < group_len; j++) {
                s_temp[j] = s[i * group_len + j];
            }
            s_temp[group_len] = '\0';
            reverse(s_temp);
            fprintf(output_file, "%s", s_temp);
        }
        fprintf(output_file, "\n");
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}