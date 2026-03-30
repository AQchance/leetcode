#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class Solution {
private:
    std::vector<std::vector<int>> ans;
    std::vector<int> path;

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0);
        return ans;
    }
    void helper(std::vector<int>& candidates, int target, int start_index)
    {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = start_index; i < candidates.size();) {
            path.push_back(candidates[i]);
            helper(candidates, target - candidates[i], i + 1);
            path.pop_back();
            i++;
            while (i < candidates.size() && candidates[i] == candidates[i - 1]) {
                i++;
            }
        }
    }
};
