#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        k = k % nums.size();
        reverse_vec(nums, 0, nums.size() - k - 1);
        reverse_vec(nums, nums.size() - k, nums.size() - 1);
        reverse_vec(nums, 0, nums.size() - 1);
    }
    void reverse_vec(vector<int>& nums, int start, int end)
    {
        if (start >= end) {
            return;
        }
        int i = start, j = end;
        while (i < j) {
            std::swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};
