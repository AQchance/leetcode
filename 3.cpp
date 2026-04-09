#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0;
        int left = 0, right = 0;
        std::unordered_set<char> my_set;
        for (; right < s.size(); right++) {
            if (!my_set.contains(s[right])) {
                ans = std::max(ans, right - left + 1);
            } else {
                for (; left < right && my_set.contains(s[right]); left++) {
                    my_set.erase(s[left]);
                }
            }
            my_set.insert(s[right]);
        }
        return ans;
    }
};

int main()
{
    std::string s = "bbbbb";
    Solution sol;
    sol.lengthOfLongestSubstring(s);
}
