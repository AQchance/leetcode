#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        std::vector<int> ans;
        std::priority_queue<std::pair<int, int>> pq;
        for (int i = 0; i < k; i++) {
            pq.push(std::pair(nums[i], i));
        }
        ans.push_back(pq.top().first);
        for (int i = k; i < nums.size(); i++) {
            pq.emplace(nums[i], i);
            while (pq.top().second < i - k + 1) {
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};
