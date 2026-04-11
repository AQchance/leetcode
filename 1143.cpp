#include <string>
#include <vector>

using namespace std;

// NOTE: 依旧是从递归入手，最开始的思路是正确的，但是时间复杂度高达O(2^(M+N))
// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2)
//     {
//         return helper(text1, text2, 0, text1.size() - 1, 0, text2.size() - 1);
//     }
//     int helper(const string& text1, const string& text2, int left_start, int left_end, int right_start, int right_end)
//     {
//         if (left_start > left_end || right_start > right_end) {
//             return 0;
//         }
//         if (text1[left_start] == text2[right_start]) {
//             return 1 + helper(text1, text2, left_start + 1, left_end, right_start + 1, right_end);
//         }
//         int ans = helper(text1, text2, left_start, left_end, right_start + 1, right_end);
//         ans = std::max(ans, helper(text1, text2, left_start + 1, left_end, right_start, right_end));
//         return ans;
//     }
// };

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size(), n = text2.size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[m][n];
    }
};
