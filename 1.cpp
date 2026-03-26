#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        std::unordered_map<int, int> m;
        std::vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (m.contains(target - nums[i])) {
                ans.push_back(i);
                ans.push_back(m[target - nums[i]]);
                break;
            }
            m[nums[i]] = i;
        }
        return ans;
    }
};
