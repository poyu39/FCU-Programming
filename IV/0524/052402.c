#include <stdio.h>
#include <math.h>


int main() {
    float start = 0;
    float end = 0;
    while (scanf("%f %f", &start, &end)) {
        if (start == 0 && end == 0) break;
        int count = 0;
        for (int i = sqrt(start); i <= sqrt(end); i++) {
            if (i * i >= start && i * i <= end) {
                count++;
            }
        }
        printf("%d\n", count);
    }
}