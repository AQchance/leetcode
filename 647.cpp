#include <string>

using namespace std;

class Solution {
public:
    int countSubstrings(string s)
    {
        int cnt = 0;
        for (int i = 0; i < s.size() * 2; i++) {
            if (i % 2 == 0) {
                int index = i / 2;
                for (int j = 0; index - j >= 0 && index + j < s.size(); j++) {
                    if (s[index - j] == s[index + j]) {
                        cnt++;
                    } else {
                        break;
                    }
                }
            } else {
                int left = (i - 1) / 2;
                int right = (i + 1) / 2;
                for (int j = 0; left - j >= 0 && right + j < s.size(); j++) {
                    if (s[left - j] == s[right + j]) {
                        cnt++;
                    } else {
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};

int main()
{
    Solution sol;
    std::string s = "abc";
    sol.countSubstrings(s);
}
