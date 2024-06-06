#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Slogan {
    char key[100];
    char value[100];
};

int main() {
    int n = 0;
    scanf("%d\n", &n);
    struct Slogan *slogans = (struct Slogan *)malloc(n * sizeof(struct Slogan));
    for (int i = 0 ; i < n; i++) {
        gets(slogans[i].key);
        gets(slogans[i].value);
    }
    int q = 0;
    scanf("%d\n", &q);
    for (int i = 0; i < q; i++) {
        char key[100] = "";
        gets(key);
        for (int j = 0; j < n; j++) {
            if (strcmp(key, slogans[j].key) == 0) {
                printf("%s\n", slogans[j].value);
                break;
            }
        }
    }
    free(slogans);
}