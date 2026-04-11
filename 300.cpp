#include <vector>

using namespace std;

// NOTE: 这道题用的是纯粹的递归，时间复杂度高达O(3^N)
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums)
//     {
//         int current_length = 0;
//         return helper(nums, 0, -10001, current_length);
//     }
//     int helper(vector<int> nums, int start_index, int current_max, int current_length)
//     {
//         if (start_index >= nums.size()) {
//             return current_length;
//         }
//         int ans = 0;
//         ans = std::max(ans, helper(nums, start_index + 1, current_max, current_length));
//         ans = std::max(ans, helper(nums, start_index + 1, -10001, 0));
//         if (nums[start_index] > current_max) {
//             ans = std::max(ans, helper(nums, start_index + 1, nums[start_index], current_length + 1));
//         }
//         return ans;
//     }
// };
//

// NOTE: 基于上面的递归的思路，改写为动态规划，时间复杂度可以降低到O(N^2)
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums)
//     {
//         std::vector<int> dp(nums.size(), 0);
//         int ans = 1;
//         dp[0] = 1;
//         for (int i = 1; i < nums.size(); i++) {
//             int j = i - 1;
//             for (; j >= 0; j--) {
//                 if (nums[i] > nums[j]) {
//                     dp[i] = std::max(dp[i], dp[j] + 1);
//                 }
//             }
//             if (dp[i] == 0) {
//                 dp[i] = 1;
//             }
//             ans = std::max(ans, dp[i]);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        std::vector<int> dp(nums.size() + 1, 0);
        int len = 1;
        dp[1] = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int left = 1, right = len;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (dp[mid] >= nums[i]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            if (right == len) {
                dp[len + 1] = nums[i];
                len++;
            } else {
                dp[right + 1] = std::min(dp[right + 1], nums[i]);
            }
        }
    }
};
