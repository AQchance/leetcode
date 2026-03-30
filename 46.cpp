#include <vector>

using namespace std;

class Solution {
private:
    std::vector<std::vector<int>> ans;
    std::vector<int> path;

public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        std::vector<bool> used(nums.size(), false);
        helper(nums, used);
        return ans;
    }
    void helper(vector<int>& nums, vector<bool>& used)
    {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            helper(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
};
