#include <stdio.h>

int is_subset_sum(int lb_length[], int lb_count, int target) {
    if (target == 0) return 1;
    if (lb_count == 0 && target != 0) return 0;
    if (lb_length[lb_count - 1] > target) return is_subset_sum(lb_length, lb_count - 1, target);
    return is_subset_sum(lb_length, lb_count - 1, target) || is_subset_sum(lb_length, lb_count - 1, target - lb_length[lb_count - 1]);
}

int main() {
    int case_total;
    scanf("%d", &case_total);
    for (int i = 0; i < case_total; i++) {
        int target;
        int lb_count;
        int lb_length[20];
        scanf("%d", &target);
        scanf("%d", &lb_count);
        for (int j = 0; j < lb_count; j++) {
            scanf("%d", &lb_length[j]);
        }
        if (is_subset_sum(lb_length, lb_count, target)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}