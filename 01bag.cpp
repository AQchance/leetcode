#include <iostream>
#include <vector>

int main()
{
    int m, n;
    std::cin >> m >> n;
    std::vector<int> space;
    std::vector<int> value;
    for (int i = 0; i < m; i++) {
        int tmp;
        std::cin >> tmp;
        space.push_back(tmp);
    }
    for (int i = 0; i < m; i++) {
        int tmp;
        std::cin >> tmp;
        value.push_back(tmp);
    }
    // NOTE: 这里的二维数组实际上是可以压缩成为一维数组的
    // std::vector<std::vector<int>> dp(m, std::vector<int>(n + 1, 0));
    // for (int j = space[0]; j <= n; j++) {
    //     dp[j][0] = value[0];
    // }
    // for (int i = 1; i < m; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         if (j < space[i]) {
    //             dp[i][j] = dp[i - 1][j];
    //         } else {
    //             dp[i][j] = std::max(dp[i - 1][j], value[i] + dp[i - 1][j - space[i]]);
    //         }
    //     }
    // }
    // std::cout << dp[m - 1][n] << '\n';
    std::vector<int> dp(n + 1, 0);
    for (int i = 0; i < m; i++) {
        for (int j = n; j >= space[i]; j--) {
            dp[j] = std::max(dp[j], dp[j - space[i]] + value[i]);
        }
    }
    std::cout << dp[n] << '\n';
}
