#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string decodeString(string s)
    {
        std::string ans;
        std::stack<char> st;
        for (const auto ch : s) {
            if (ch != ']') {
                st.push(ch);
            } else {
                std::string tmp;
                while (st.top() != '[') {
                    tmp = st.top() + tmp;
                    st.pop();
                }
                st.pop();
                int n = 0;
                int m = 1;
                while (!st.empty() && st.top() <= '9' && st.top() >= '0') {
                    n += (st.top() - '0') * m;
                    m *= 10;
                    st.pop();
                }
                for (int j = 0; j < n; j++) {
                    for (int i = 0; i < tmp.size(); i++) {
                        st.push(tmp[i]);
                    }
                }
            }
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
