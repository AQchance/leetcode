#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            for (; left <= right && nums[left] != val; left++) {
            }
            for (; left <= right && nums[right] == val; right--) {
            }
            if (left <= right) {
                std::swap(nums[left], nums[right]);
            }
        }
        return left;
    }
};
