#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(amount + 1, 0));
        for (int j = 1; j <= amount; j++) {
            dp[0][j] = -1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                if (j >= coins[i - 1]) {
                    if (dp[i - 1][j] < 0 && dp[i][j - coins[i - 1]] < 0) {
                        dp[i][j] = -1;
                    } else if (dp[i - 1][j] < 0 && dp[i][j - coins[i - 1]] >= 0) {
                        dp[i][j] = dp[i][j - coins[i - 1]] + 1;
                    } else if (dp[i - 1][j] >= 0 && dp[i][j - coins[i - 1]] < 0) {
                        dp[i][j] = dp[i - 1][j];
                    } else {
                        dp[i][j] = std::min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
                    }
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][amount];
    }
};
