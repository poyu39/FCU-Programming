#include <stdio.h>

void cal_jumps(int* walls, int walls_len, int* high, int* low) {
    for (int i = 0; i < walls_len - 1; i++) {
        if (walls[i] < walls[i + 1]) {
            *high += 1;
        } else if (walls[i] > walls[i + 1]) {
            *low += 1;
        }
    }
}

int main() {
    int t, n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        int walls[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", &walls[j]);
        }
        printf("Case %d: ", i + 1);
        int high = 0, low = 0;
        cal_jumps(walls, n, &high, &low);
        printf("%d %d\n", high, low);
    }
}