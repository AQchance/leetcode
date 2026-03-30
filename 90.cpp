#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    std::vector<std::vector<int>> ans;
    std::vector<int> path;

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        ans.push_back(path);
        std::sort(nums.begin(), nums.end());
        for (int k = 1; k <= nums.size(); k++) {
            helper(nums, 0, k);
        }
        return ans;
    }
    void helper(vector<int>& nums, int start_index, int k)
    {
        if (k == 0) {
            ans.push_back(path);
        }
        for (int i = start_index; i < nums.size();) {
            path.push_back(nums[i]);
            helper(nums, i + 1, k - 1);
            path.pop_back();
            i++;
            while (i < nums.size() && nums[i] == nums[i - 1]) {
                i++;
            }
        }
    }
};
