#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, sum_weight;
    std::cin >> n >> sum_weight;
    std::vector<int> item_weight(n, 0);
    std::vector<int> item_value(n, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> item_weight[i];
        std::cin >> item_value[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(sum_weight + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum_weight; j++) {
            if (j < item_weight[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - item_weight[i - 1]] + item_value[i - 1]);
            }
        }
    }
    std::cout << dp[n][sum_weight] << '\n';
}
