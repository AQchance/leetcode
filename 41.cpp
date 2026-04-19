#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (1 <= nums[i] && nums[i] <= n && nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }
        int ans = n + 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > n || nums[i] < 1 || nums[i] != i + 1) {
                ans = i + 1;
                break;
            }
        }
        return ans;
    }
};
