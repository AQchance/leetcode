#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s)
    {
        int ans = 0;
        std::stack<int> st;
        std::vector<int> dp(s.size(), s.size());
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (!st.empty()) {
                    dp[st.top()] = i;
                    st.pop();
                }
            }
        }
        while (!st.empty()) {
            dp[st.top()] = s.size();
            st.pop();
        }
        for (int i = 0; i < s.size();) {
            while (i < s.size() && dp[i] >= s.size()) {
                i++;
            }
            int cnt = 0;
            while (i < s.size() && dp[i] < s.size()) {
                cnt += dp[i] - i + 1;
                i = dp[i] + 1;
            }
            ans = std::max(ans, cnt);
        }
        return ans;
    }
};
