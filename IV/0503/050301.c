#include <stdio.h>
#include <string.h>

int main() {
    int case_total;
    scanf("%d", &case_total);
    for (int i = 0; i < case_total; i++) {
        int inst_total;
        int inst[100];
        scanf("%d", &inst_total);
        for (int j = 0; j < inst_total; j++) {
            char buffer[10];
            scanf("%s", buffer);
            if (strcmp(buffer, "LEFT") == 0) inst[j] = -1;
            if (strcmp(buffer, "RIGHT") == 0) inst[j] = 1;
            if (strcmp(buffer, "SAME") == 0) {
                int k;
                scanf("%s %d", buffer, &k);
                inst[j] = inst[k - 1];
            }
        }
        int pos = 0;
        for (int j = 0; j < inst_total; j++) {
            pos += inst[j];
        }
        printf("%d\n", pos);
    }
}