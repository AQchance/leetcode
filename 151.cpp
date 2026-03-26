#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s)
    {
        int i = 0;
        if (s[0] == ' ') {
            for (; s[i] == ' '; i++) { }
            s.erase(0, i);
        }
        if (s[s.size() - 1] == ' ') {
            i = s.size() - 1;
            for (; s[i] == ' '; i--) { }
            s.erase(i + 1, s.size() - i - 1);
        }
        // 整体倒置
        std::reverse(s.begin(), s.end());
        auto left = s.begin(), right = s.begin();
        for (auto iter = s.begin(); iter != s.end();) {
            if (iter + 1 == s.end()) {
                right = iter;
                std::reverse(left, right + 1);
                iter++;
            } else {
                if (*iter != ' ' && *(iter + 1) == ' ') {
                    right = iter;
                    std::reverse(left, right + 1);
                    iter++;
                } else if (*iter == ' ' && *(iter + 1) == ' ') {
                    s.erase(iter);
                } else if (*iter == ' ' && *(iter + 1) != ' ') {
                    left = iter + 1;
                    iter++;
                } else {
                    iter++;
                }
            }
        }
        return s;
    }
};
