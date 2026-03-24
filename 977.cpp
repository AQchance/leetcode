#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        vector<int> ans(nums.size());
        int index = ans.size();
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            if (abs(nums[i]) > abs(nums[j])) {
                ans[--index] = nums[i] * nums[i];
                i++;
            } else {
                ans[--index] = nums[j] * nums[j];
                j--;
            }
        }
        return ans;
    }
};
