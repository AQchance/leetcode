#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n)
    {
        std::vector<int> dp(n + 1, 0);
        int base_num = 1;
        for (int i = 1; i <= n; i++) {
            if (base_num * 2 <= i) {
                base_num *= 2;
            }
            dp[i] = 1 + dp[i - base_num];
        }
        return dp;
    }
};
