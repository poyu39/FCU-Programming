#include <stdio.h>
#include <stdlib.h>


void delete_dumplicate(int *cards, int *size) {
    for (int i = 0; i < *size; i++) {
        for (int j = i + 1; j < *size; j++) {
            if (cards[i] == cards[j]) {
                for (int k = j; k < *size - 1; k++) {
                    cards[k] = cards[k + 1];
                }
                (*size)--;
                j--;
            }
        }
    }
}

int main() {
    while (1) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0) break;

        int *a_cards = (int *)malloc(a * sizeof(int));
        int *b_cards = (int *)malloc(b * sizeof(int));

        for (int i = 0; i < a; i++) scanf("%d", &a_cards[i]);
        for (int i = 0; i < b; i++) scanf("%d", &b_cards[i]);

        delete_dumplicate(a_cards, &a);
        delete_dumplicate(b_cards, &b);

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (a_cards[i] == b_cards[j]) {
                    for (int k = i; k < a - 1; k++) a_cards[k] = a_cards[k + 1];
                    a--;
                    i--;
                    for (int k = j; k < b - 1; k++) b_cards[k] = b_cards[k + 1];
                    b--;
                    j--;
                }
            }
        }
        printf("%d\n", a < b ? a : b);

        free(a_cards);
        free(b_cards);
    }
    return 0;
}