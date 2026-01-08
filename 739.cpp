#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        std::stack<int> res;
        std::vector<int> ans;
        ans.resize(temperatures.size());
        for (size_t i = 0; i < temperatures.size(); i++) {
            if (res.empty() || temperatures[i] <= temperatures[res.top()]) {
                res.push(i);
                continue;
            }
            while (!res.empty() && temperatures[res.top()] < temperatures[i]) {
                ans[res.top()] = i - res.top();
                res.pop();
            }
            res.push(i);
        }
        while (!res.empty()) {
            ans[res.top()] = 0;
            res.pop();
        }
        return ans;
    }
};

int main()
{
    std::vector<int> temperatures { 73, 74, 75, 71, 69, 72, 76, 73 };
    Solution sol;
    std::vector<int> ans = sol.dailyTemperatures(temperatures);
    int a = ans.size();
    return 0;
}
