#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n)
    {
        // NOTE: 这样是先找出来完全平方数，再使用一次完全背包，不是最优解
        // std::vector<int> sqrt_nums;
        // for (int i = 1; i <= n; i++) {
        //     int tmp = std::sqrt(i);
        //     if (tmp * tmp == i) {
        //         sqrt_nums.push_back(i);
        //     }
        // }
        // int size = sqrt_nums.size();
        // std::vector<std::vector<int>> dp(size + 1, std::vector<int>(n + 1, n + 1));
        // dp[0][0] = 0;
        // for (int i = 1; i <= size; i++) {
        //     for (int j = 0; j <= n; j++) {
        //         if (j < sqrt_nums[i - 1]) {
        //             dp[i][j] = dp[i - 1][j];
        //         } else {
        //             dp[i][j] = std::min(dp[i - 1][j], dp[i][j - sqrt_nums[i - 1]] + 1);
        //         }
        //     }
        // }
        // return dp[size][n];
        std::vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = std::min(dp[i], 1 + dp[i - j * j]);
            }
        }
        return dp[n];
    }
};
