#include <stdio.h>

int find_m(int k, int m) {
    int people = k * 2;
    int i = 0;
    int kill;
    while (people != k) {
        kill = (kill + (m - 1) % people) % people;
        if (kill >= k) {
            people--;
        } else {
            people = k * 2;
            m++;
            kill = 0;
        }
    }
    return m;
}

int main() {
    int k;
    int cases[14] = {0};
    for (int i = 1; i <= 13; i++) {
        cases[i] = find_m(i, i);
    }
    while (scanf("%d", &k) != EOF) {
        if (k < 1 || k > 13) break;
        printf("%d\n", cases[k]);
    }
    return 0;
}