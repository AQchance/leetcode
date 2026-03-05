#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums)
    {
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return std::max(nums[1], nums[0]);
        }
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        for (size_t i = 2; i < nums.size(); i++) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[dp.size() - 1];
    }
};
