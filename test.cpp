#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int m, n;
    std::cin >> n >> m;
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j <= i) {
                dp[i] += dp[i - j];
            }
        }
    }
    std::cout << dp[n] << '\n';
}
