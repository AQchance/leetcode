#include <cinttypes>
#include <queue>
#include <vector>

using namespace std;

// NOTE: 官方左右脑互搏
// 而且给出的数据有很多的重复，这样的话该方法会退化到O(N^2)
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k)
//     {
//         int position = 0;
//         int start = 0, end = nums.size() - 1;
//         while (true) {
//             position = find_pivot(nums, start, end);
//             if (position == k - 1) {
//                 break;
//             } else if (position > k - 1) {
//                 end = position - 1;
//             } else if (position < k - 1) {
//                 start = position + 1;
//             }
//         }
//         return nums[position];
//     }
//
//     int find_pivot(vector<int>& nums, int start, int end)
//     {
//         if (start == end) {
//             return start;
//         }
//         int tmp = nums[start];
//         size_t i = start, j = end;
//         while (i < j) {
//             for (; nums[j] <= tmp && i < j; j--) { }
//             std::swap(nums[i], nums[j]);
//             for (; nums[i] >= tmp && i < j; i++) { }
//             std::swap(nums[i], nums[j]);
//         }
//         nums[i] = tmp;
//         return i;
//     }
// };

// NOTE: 使用堆来做，但是时间复杂度是O(N + k * logN)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        std::priority_queue<int> p_queue;
        for (auto num : nums) {
            p_queue.push(num);
        }
        for (int i = 0; i < k - 1; i++) {
            p_queue.pop();
        }
        return p_queue.top();
    }
};
