#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int left = 0, right = nums.size() - 1;
        int n = nums.size();
        while (1) {
            int k = pivot(nums, left, right);
            if (k == n / 2) {
                return nums[k];
            } else if (k > n / 2) {
                right = k - 1;
            } else if (k < n / 2) {
                left = k + 1;
            }
        }
    }

private:
    int pivot(vector<int>& nums, int left, int right)
    {
        if (left == right) {
            return left;
        }
        int num = nums[left];
        int i = left, j = right;
        while (i < j) {
            for (; nums[j] >= num && i < j; j--) {
            }
            nums[i] = nums[j];
            if (i == j) {
                break;
            }
            for (; nums[i] <= num && i < j; i++) {
            }
            nums[j] = nums[i];
            if (i == j) {
                nums[i] = num;
                break;
            }
        }
        return i;
    }
};

int main()
{
    vector<int> test = { 3, 2, 3 };
    Solution sol;
    sol.majorityElement(test);
}
