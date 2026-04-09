#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int ans = -10001;
        std::vector<int> dp(nums.size() + 1, -10001);
        for (int i = 1; i <= nums.size(); i++) {
            dp[i] = std::max(dp[i - 1] + nums[i - 1], nums[i - 1]);
            ans = std::max(ans, dp[i]);
        }
        return ans;
    }
};
