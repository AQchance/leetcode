#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // 这道题目似乎是要用滑动窗口来做的
    vector<int> findAnagrams(string s, string p)
    {
        // abab,ab
        int left = 0, right = p.size() - 1;
        std::vector<int> ans;
        for (int i = 0; right < s.size(); i++) {
            if (left <= i && i <= right) {
                // 还在窗口内部
                int pos = p.size();
                while (pos > 0) {
                    int index = p.find(s[i]);
                    if (index != std::string::npos && index < pos) {
                        p.erase(index, 1);
                        p.push_back(s[i]);
                        pos--;
                        i++;
                    } else if (index == std::string::npos) {
                        // 这个时候说明没有找到
                        left = i + 1;
                        right = i + p.size();
                        break;
                    } else {
                        // 找到了但是这个字母的数量不够。
                        i = left;
                        left++;
                        right++;
                        break;
                    }
                }
                if (pos == 0) {
                    ans.push_back(i - p.size());
                    i--;
                }
            } else {
                // 这个时候i正好在right的右边1位，
                if (s[i] == s[i - p.size()]) {
                    ans.push_back(i - p.size() + 1);
                    left++;
                    right++;
                } else {
                    i = left;
                    left++;
                    right++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    std::string s = "abacbabc";
    std::string p = "abc";
    sol.findAnagrams(s, p);
}
