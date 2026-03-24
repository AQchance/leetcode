#include <algorithm>
#include <vector>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
    if (a[0] < b[0]) {
        return true;
    }
    if (a[0] > b[0]) {
        return false;
    }
    if (a[1] > b[1]) {
        return true;
    }
    return false;
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        std::vector<vector<int>> ans(people.size(), std::vector<int> { -1, -1 });
        std::sort(people.begin(), people.end(), cmp);
        for (auto& item : people) {
            int cnt = 0;
            int index = 0;
            for (; index < ans.size(); index++) {
                if (ans[index][0] == -1) {
                    cnt++;
                }
                if (cnt > item[1]) {
                    ans[index][0] = item[0];
                    ans[index][1] = item[1];
                    break;
                }
            }
        }
        return ans;
    }
};
