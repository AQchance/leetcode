#include <vector>

using namespace std;

class Solution {
private:
    std::vector<int> path;
    std::vector<std::vector<int>> ans;

public:
    vector<vector<int>> combine(int n, int k)
    {
        helper(n, k, 1);
        return ans;
    }
    void helper(int n, int k, int start_index)
    {
        if (k == 0) {
            ans.push_back(path);
            return;
        }
        for (int i = start_index; i <= n - k + 1; i++) {
            path.push_back(i);
            helper(n, k - 1, i + 1);
            path.pop_back();
        }
    }
};
