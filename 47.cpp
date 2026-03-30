#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    std::vector<int> path;
    std::vector<std::vector<int>> ans;

public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        std::vector<bool> used(nums.size(), false);
        std::sort(nums.begin(), nums.end());
        helper(nums, used);
        return ans;
    }
    void helper(vector<int>& nums, vector<bool>& used)
    {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size();) {
            if (used[i]) {
                i++;
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            helper(nums, used);
            path.pop_back();
            used[i] = false;
            i++;
            while (i < nums.size() && nums[i] == nums[i - 1]) {
                i++;
            }
        }
    }
};
