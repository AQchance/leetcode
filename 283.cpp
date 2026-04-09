#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int left = 0, right = 0;
        while (left < nums.size() && right < nums.size()) {
            // left指向左边第一个为0的值
            for (; left < nums.size() && nums[left] != 0; left++) {
            }
            // right指向left右边第一个不为0的值
            for (right = left + 1; right < nums.size() && nums[right] == 0; right++) {
            }
            if (left < nums.size() && right < nums.size()) {
                std::swap(nums[left], nums[right]);
            } else {
                break;
            }
        }
    }
};
