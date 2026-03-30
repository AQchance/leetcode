#include <vector>

using namespace std;

class Solution {
private:
    std::vector<std::vector<int>> ans;
    std::vector<int> path;

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        helper(candidates, target, 0);
        return ans;
    }
    void helper(std::vector<int> candidates, int target, int start_index)
    {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = start_index; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            helper(candidates, target - candidates[i], i);
            path.pop_back();
        }
    }
};
