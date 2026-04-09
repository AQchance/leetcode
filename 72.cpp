#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        if (m == 0) {
            return n;
        }
        if (n == 0) {
            return m;
        }
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int left_dist = dp[i - 1][j] + 1;
                int right_dist = dp[i][j - 1] + 1;
                int tmp = dp[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1]) {
                    tmp++;
                }
                dp[i][j] = std::min(left_dist, std::min(right_dist, tmp));
            }
        }
        return dp[m][n];
    }
};
