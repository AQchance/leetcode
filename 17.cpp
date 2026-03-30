#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    std::vector<string> ans;
    std::string path;

    std::vector<std::string> phone = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

public:
    vector<string> letterCombinations(string digits)
    {
        helper(digits, 0);
        return ans;
    }
    void helper(string digits, int start_index)
    {
        if (path.size() == digits.size()) {
            ans.push_back(path);
            return;
        }
        std::string str = phone[digits[start_index] - '0'];
        for (int i = 0; i < str.size(); i++) {
            path.push_back(str[i]);
            helper(digits, start_index + 1);
            path.pop_back();
        }
    }
};
