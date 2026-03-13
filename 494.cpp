#include <vector>

using namespace std;

// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target)
//     {
//         return assist_func(nums, target, 0);
//     }
//     int assist_func(vector<int>& nums, int target, int pos)
//     {
//         if (pos == nums.size()) {
//             if (target == 0) {
//                 return 1;
//             } else {
//                 return 0;
//             }
//         }
//         int cnt = 0;
//         cnt += assist_func(nums, target + nums[pos], pos + 1);
//         cnt += assist_func(nums, target - nums[pos], pos + 1);
//         return cnt;
//     }
// };

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }
        if ((sum - target) % 2 != 0 || (sum - target) < 0) {
            return 0;
        }
        int neg = (sum - target) / 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(neg + 1, 0));
        dp[0][0] = 1;
        for (size_t i = 1; i <= nums.size(); i++) {
            int num = nums[i - 1];
            for (size_t j = 0; j <= neg; j++) {
                // 现在已经有了dp[i-1][j], dp[i-1][j-1], 以及dp[i][j-1]
                if (num > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - num];
                }
            }
        }
        return dp[nums.size()][neg];
    }
};
