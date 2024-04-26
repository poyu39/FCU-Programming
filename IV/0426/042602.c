#include <stdio.h>
#include <string.h>

int main() {
    int target;
    int coins[5] = {50, 25, 10, 5, 1};
    while (scanf("%d", &target) != EOF) {
        int count = 0;
        int dp[7490];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < 5; i++) {
            for (int j = coins[i]; j <= target; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        count = dp[target];
        printf("%d\n", count);
    }
    return 0;
}