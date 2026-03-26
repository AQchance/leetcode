#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> ans;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size();) {
            for (int j = i + 1; j < nums.size();) {
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    long num1 = nums[left] + nums[right];
                    long num2 = target - nums[i];
                    num2 = num2 - nums[j];
                    if (num1 > num2) {
                        right--;
                        while (left < right && nums[right] == nums[right + 1]) {
                            right--;
                        }
                    } else if (num1 < num2) {
                        left++;
                        while (left < right && nums[left] == nums[left - 1]) {
                            left++;
                        }
                    } else {
                        ans.push_back(std::vector<int> { nums[i], nums[j], nums[left], nums[right] });
                        right--;
                        left++;
                        while (left < right && nums[right] == nums[right + 1]) {
                            right--;
                        }
                        while (left < right && nums[left] == nums[left - 1]) {
                            left++;
                        }
                    }
                }
                j++;
                while (j < nums.size() && nums[j] == nums[j - 1]) {
                    j++;
                }
            }
            i++;
            while (i < nums.size() && nums[i] == nums[i - 1]) {
                i++;
            }
        }
        return ans;
    }
};
