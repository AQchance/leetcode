#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }
        sum /= 2;
        // 现在的问题就转换成了是否存在选取若干个数字，使得和等于sum
        // dp[i]表示是否在前i个值里面有sum.
        vector<int> dp(sum + 1, false);
        dp[0] = 1;
        for (auto num : nums) {
            for (int j = sum; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        if (dp[sum] == true) {
            return true;
        }
        return dp[sum];
    }
};
