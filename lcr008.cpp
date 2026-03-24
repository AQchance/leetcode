#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int left = 0, right = 0;
        int ans = nums.size();
        int sum = 0;
        bool flag = false;
        for (; right < nums.size(); right++) {
            sum += nums[right];
            if (sum < target) {
                continue;
            } else {
                flag = true;
                for (; left <= right && sum >= target; left++) {
                    ans = std::min(ans, right - left + 1);
                    sum -= nums[left];
                }
            }
        }
        if (flag) {
            return ans;
        }
        return 0;
    }
};
