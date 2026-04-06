#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n)
    {
        std::vector<int> dp(n + 1, 0);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int k = 2; k < i; k++) {
                dp[i] = std::max(dp[i], std::max(k * (i - k), dp[k] * (i - k)));
            }
        }
        return dp[n];
    }
};
