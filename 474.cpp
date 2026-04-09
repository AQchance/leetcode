#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        // NOTE: 这个是三维数组的形式，实际上可以降维为二维数组
        // int size = strs.size();
        // vector<vector<vector<int>>> dp(size + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        // int zero_num = 0, one_num = 0;
        //
        // for (int i = 1; i <= size; i++) {
        //     const string& str_tmp = strs[i - 1];
        //     zero_num = 0, one_num = 0;
        //     for (const auto ch : str_tmp) {
        //         if (ch == '0') {
        //             zero_num++;
        //         } else {
        //             one_num++;
        //         }
        //     }
        //     for (int j = 0; j <= m; j++) {
        //         for (int k = 0; k <= n; k++) {
        //             if (j < zero_num || k < one_num) {
        //                 dp[i][j][k] = dp[i - 1][j][k];
        //             } else {
        //                 dp[i][j][k] = std::max(dp[i - 1][j][k], 1 + dp[i - 1][j - zero_num][k - one_num]);
        //             }
        //         }
        //     }
        // }
        // return dp[size][m][n];
        int size = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (const auto& str : strs) {
            int zero_num = 0, one_num = 0;
            for (const auto ch : str) {
                if (ch == '0') {
                    zero_num++;
                } else {
                    one_num++;
                }
            }
            for (int j = m; j >= zero_num; j--) {
                for (int k = n; k >= one_num; k--) {
                    dp[j][k] = std::max(dp[j][k], 1 + dp[j - zero_num][k - one_num]);
                }
            }
        }
        return dp[m][n];
    }
};
