#include <vector>

using namespace std;

class Solution {
private:
    std::vector<std::vector<int>> ans;
    std::vector<int> path;

public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        ans.push_back(path);
        for (int k = 1; k <= nums.size(); k++) {
            helper(nums, 0, k);
        }
        return ans;
    }
    void helper(std::vector<int>& nums, int start_index, int k)
    {
        if (k == 0) {
            ans.push_back(path);
            return;
        }
        for (int i = start_index; i < nums.size(); i++) {
            path.push_back(nums[i]);
            helper(nums, i + 1, k - 1);
            path.pop_back();
        }
    }
};
