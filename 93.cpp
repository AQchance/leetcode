#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    std::vector<std::string> ans;
    std::string path;

public:
    vector<string> restoreIpAddresses(string s)
    {
        helper(s, 0, 4);
        return ans;
    }
    void helper(const std::string& s, int start_index, int k)
    {
        if (start_index >= s.size() && k == 0) {
            path.pop_back();
            ans.push_back(path);
            return;
        }
        if (k == 0) {
            return;
        }
        for (int size = 1; size <= 3 && start_index + size - 1 < s.size(); size++) {
            std::string str = s.substr(start_index, size);
            int num = std::stoi(str);
            if (str.size() > 1 && str[0] == '0') {
                continue;
            }
            if (num >= 0 && num <= 255) {
                path = path + str + '.';
                helper(s, start_index + size, k - 1);
                path.pop_back();
                while (path.size() > 0 && path[path.size() - 1] != '.') {
                    path.pop_back();
                }
            }
        }
    }
};
