#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        int size = coins.size();
        std::vector<std::vector<long>> dp(size + 1, std::vector<long>(amount + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= size; i++) {
            for (int j = 0; j <= amount; j++) {
                if (j < coins[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                    if (dp[i][j] > INT_MAX) {
                        dp[i][j] = INT_MAX;
                    }
                }
            }
        }
        return dp[size][amount];
    }
};
