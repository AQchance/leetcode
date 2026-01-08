#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int ans = 0;
        std::vector<std::vector<int>> dp(matrix.size(), std::vector<int>(matrix[0].size()));
        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = std::min(std::min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    ans = std::max(ans, dp[i][j]);
                }
            }
        }
        return ans * ans;
    }
};
