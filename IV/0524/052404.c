#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define CHARACTERS 26

struct Character
{
    char c;
    int count;
};


int is_in_array(char c, char *array, int len) {
    for (int i = 0; i < len; i++) {
        if (c == array[i]) {
            return 1;
        }
    }
    return 0;
}

int sort(struct Character *char_count, int len) {
    // sort by count
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (char_count[i].count < char_count[j].count) {
                struct Character temp = char_count[i];
                char_count[i] = char_count[j];
                char_count[j] = temp;
            }
        }
    }
    // sort by char
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (char_count[i].count == char_count[j].count && char_count[i].c > char_count[j].c) {
                struct Character temp = char_count[i];
                char_count[i] = char_count[j];
                char_count[j] = temp;
            }
        }
    }
}

int main() {
    struct Character char_count[CHARACTERS];
    for (int i = 0; i < CHARACTERS; i++) {
        char_count[i].c = 'A' + i;
        char_count[i].count = 0;
    }
    int len = 0;
    scanf("%d\n", &len);
    while (len--) {
        char buffer[100] = "";
        gets(buffer);
        for (int j = 0; buffer[j] != '\0'; j++) {
            if (isalpha(buffer[j]) == 0) continue;
            buffer[j] = toupper(buffer[j]);
            if (is_in_array(buffer[j], "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26)) {
                char_count[buffer[j] - 'A'].count++;
            }
        }
    }
    sort(char_count, CHARACTERS);
    for (int i = 0; i < CHARACTERS; i++) {
        if (char_count[i].count == 0) continue;
        printf("%c %d\n", char_count[i].c, char_count[i].count);
    }
}