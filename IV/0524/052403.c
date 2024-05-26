#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SHIFT 100


int get_mean(int *arr, int len) {
    double mean = 0;
    for (int i = 0; i < len; i++) {
        mean += arr[i];
    }
    return round(mean / len);
}

int main() {
    int n = 0;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        int *expenses = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            int d = 0, c = 0;
            // c = cents, d = dollars
            scanf("%d.%d", &d, &c);
            expenses[i] = d * SHIFT + c;
        }
        
        int mean = 0;
        double h2l_diff = 0, l2h_diff = 0;
        mean = get_mean(expenses, n);
        for (int i = 0; i < n; i++) {
            if (expenses[i] > mean) h2l_diff += (expenses[i] - mean);
            if (expenses[i] < mean) l2h_diff += (mean - expenses[i]);
        }
        int diff = h2l_diff < l2h_diff ? h2l_diff : l2h_diff;
        if (diff == 0) diff = (h2l_diff + l2h_diff) / 2;
        printf("$%d.%02d\n", diff / SHIFT, diff % SHIFT);
        free(expenses);
    }
    return 0;
}