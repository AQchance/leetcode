#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        std::vector<int> dp(2);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= cost.size(); i++) {
            dp.push_back(std::min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]));
        }
        return dp.back();
    }
};
