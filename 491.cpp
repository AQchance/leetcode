#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
    std::vector<int> path;
    std::vector<std::vector<int>> ans;

public:
    vector<vector<int>> findSubsequences(vector<int>& nums)
    {
        helper(nums, 0);
        return ans;
    }
    void helper(vector<int>& nums, int start_index)
    {
        std::unordered_set<int> used;
        for (int i = start_index; i < nums.size(); i++) {
            if (used.contains(nums[i])) {
                continue;
            }
            used.insert(nums[i]);
            if (path.empty()) {
                path.push_back(nums[i]);
                helper(nums, i + 1);
                path.pop_back();
            } else {
                if (path.back() <= nums[i]) {
                    path.push_back(nums[i]);
                    helper(nums, i + 1);
                    if (path.size() >= 2) {
                        ans.push_back(path);
                    }
                    path.pop_back();
                }
            }
        }
    }
};
