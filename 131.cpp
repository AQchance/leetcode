#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    std::vector<std::vector<std::string>> ans;
    std::vector<std::string> path;

public:
    vector<vector<string>> partition(string s)
    {
        helper(s, 0);
        return ans;
    }
    bool is_huiwen(const string& s, int left, int right)
    {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void helper(const string& s, int start_index)
    {
        if (start_index >= s.size()) {
            ans.push_back(path);
            return;
        }
        for (int size = 1; size <= s.size() - start_index; size++) {
            if (is_huiwen(s, start_index, start_index + size - 1)) {
                path.push_back(s.substr(start_index, size));
                helper(s, start_index + size);
                path.pop_back();
            }
        }
    }
};
