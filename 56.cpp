#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b)
{
    if (a[0] < b[0]) {
        return true;
    }
    if (a[0] == b[0]) {
        return a[1] < b[1];
    }
    return false;
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        std::sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (const auto& item : intervals) {
            if (ans.empty()) {
                ans.push_back(item);
            } else {
                if (ans.back()[1] < item[0]) {
                    ans.push_back(item);
                } else {
                    ans.back()[1] = std::max(ans.back()[1], item[1]);
                }
            }
        }
        return ans;
    }
};
