#include <cinttypes>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones)
    {
        int sum = 0;
        for (const auto num : stones) {
            sum += num;
        }
        int tmp = sum;
        sum /= 2;
        std::vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < stones.size(); i++) {
            for (int j = sum; j >= stones[i]; j--) {
                dp[j] = dp[j] || dp[j - stones[i]];
            }
        }
        int i = sum;
        for (; i >= 0 && dp[i] == 0; i--) {
        }
        tmp = tmp - i;
        return std::abs(tmp - i);
    }
};
