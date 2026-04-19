#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Info {
    int left;
    int right;
};

class Solution {
private:
    bool check(std::unordered_map<char, int>& my_map, std::unordered_map<char, int>& cnt)
    {
        for (auto& item : cnt) {
            if (!my_map.contains(item.first)) {
                return false;
            }
            if (my_map[item.first] < item.second) {
                return false;
            }
        }
        return true;
    }

public:
    string minWindow(string s, string t)
    {
        Info ans_info = { 0, 100001 };
        std::unordered_map<char, int> cnt;
        std::unordered_map<char, int> my_map;
        for (int i = 0; i < t.size(); i++) {
            cnt[t[i]]++;
        }
        int left = 0, right = -1;
        for (; right < (int)(s.size() - 1);) {
            right++;
            my_map[s[right]]++;
            while (left <= right && check(my_map, cnt)) {
                if (right - left < ans_info.right - ans_info.left) {
                    ans_info.right = right;
                    ans_info.left = left;
                }
                if (my_map[s[left]] == 1) {
                    my_map.erase(my_map.find(s[left]));
                } else {
                    my_map[s[left]]--;
                }
                left++;
            }
        }
        std::string ans;
        if (ans_info.right > 100000) {
            return ans;
        }
        ans = s.substr(ans_info.left, ans_info.right - ans_info.left + 1);
        return ans;
    }
};

int main()
{
    std::string s = "ADOBECODEBANC";
    std::string t { "ABC" };
    Solution sol;
    sol.minWindow(s, t);
}
