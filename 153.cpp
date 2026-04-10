#include <vector>

using namespace std;

// NOTE: 目前的思路是找到最大的那一个，然后直接加一求余获取下标，实际上还是麻烦了一些
// class Solution {
// public:
//     int findMin(vector<int>& nums)
//     {
//         int left = 0, right = nums.size() - 1;
//         while (left < right) {
//             int mid = (left + right) / 2;
//             if (nums[left] < nums[right]) {
//                 return nums[(right + 1) % nums.size()];
//             } else {
//                 if (nums[mid] > nums[right]) {
//                     left = mid;
//                     right--;
//                 } else {
//                     right = mid - 1;
//                 }
//             }
//         }
//         return nums[(right + 1) % nums.size()];
//     }
// };
//

class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[left] < nums[right]) {
                return nums[left];
            }
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[right];
    }
};
