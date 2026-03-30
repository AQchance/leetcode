#include <vector>

using namespace std;

class Solution {
private:
    std::vector<int> path;
    std::vector<std::vector<int>> ans;

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        helper(k, n, 1);
        return ans;
    }
    void helper(int k, int n, int start_index)
    {
        if (k == 0 && n == 0) {
            ans.push_back(path);
            return;
        }
        if (n <= 0) {
            return;
        }
        for (int i = start_index; i <= 9; i++) {
            path.push_back(i);
            helper(k - 1, n - i, i + 1);
            path.pop_back();
        }
    }
};
