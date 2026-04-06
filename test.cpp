#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int sum = 0;
        for (const auto num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }
        sum /= 2;
        // 接下来就转换成，从当前的nums数组中，找到若干个数字，使得它的总和是sum，是否存在这样的方案？
        int n = nums.size();
        // std::vector<std::vector<int>> dp(n + 1, std::vector<int>(sum + 1, 0));
        // dp[0][0] = 1;
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 0; j <= sum; j++) {
        //         if (j < nums[i - 1]) {
        //             dp[i][j] = dp[i - 1][j];
        //         } else {
        //             dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
        //         }
        //         if (j == sum && dp[i][j]) {
        //             return true;
        //         }
        //     }
        // }
        // if (dp[n][sum]) {
        //     return true;
        // } else {
        //     return false;
        // }
        std::vector<bool> dp(sum + 1, 0);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = sum; j >= nums[i]; j--) {
                dp[j] = dp[j] || dp[j - nums[i]];
                if (dp[j] && j == sum) {
                    return true;
                }
            }
        }
        if (dp[sum]) {
            return true;
        } else {
            return false;
        }
    }
};
