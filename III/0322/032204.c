#include <stdio.h>

int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int get_letter_value(char letter) {
    if (letter >= 'a' && letter <= 'z') {
        return letter - 'a' + 1;
    } else if (letter >= 'A' && letter <= 'Z') {
        return letter - 'A' + 27;
    }
    return 0;
}

int get_word_value(char* word) {
    int value = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        value += get_letter_value(word[i]);
    }
    return value;
}

int main() {
    char word[21];
    while (scanf("%s", word) != EOF) {
        int word_value = get_word_value(word);
        if (is_prime(word_value)) {
            printf("It is a prime word.\n");
        } else {
            printf("It is not a prime word.\n");
        }
    }
    return 0;
}