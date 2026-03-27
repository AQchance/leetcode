#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s)
    {
        std::string ans;
        for (auto ch : s) {
            if (ans.empty()) {
                ans.push_back(ch);
                continue;
            }
            if (ans.back() == ch) {
                ans.pop_back();
            } else {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};
