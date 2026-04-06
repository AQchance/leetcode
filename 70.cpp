#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n)
    {
        std::vector<int> dp(2);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp.push_back(dp[i - 1] + dp[i - 2]);
        }
        return dp[n];
    }
};
