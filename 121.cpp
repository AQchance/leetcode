#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int ans = 0;
        std::vector<int> dp(prices.size() + 1, 10001);
        for (int i = 1; i <= prices.size(); i++) {
            if (prices[i - 1] > dp[i - 1]) {
                ans = std::max(ans, prices[i - 1] - dp[i - 1]);
            }
            dp[i] = std::min(prices[i - 1], dp[i - 1]);
        }
        return ans;
    }
};

int main()
{
    std::vector<int> prices { 7, 1, 5, 3, 6, 4 };
    Solution sol;
    sol.maxProfit(prices);
}
