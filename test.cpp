#include <queue>
#include <vector>

using namespace std;

struct Info {
    int val;
    int index;
    Info(int val, int index)
    {
        this->val = val;
        this->index = index;
    }
    bool operator<(const Info& other) const
    {
        return val < other.val;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        std::priority_queue<Info> pq;
        std::vector<int> ans;
        for (int i = 0; i < k; i++) {
            pq.push(Info(nums[i], i));
        }
        int left = 0, right = k - 1;
        for (; right < nums.size(); right++, left++) {
            while (!pq.empty() && pq.top().index < left) {
                pq.pop();
            }
            ans.push_back(pq.top().val);
            if (right + 1 < nums.size()) {
                pq.push(Info(nums[right + 1], right + 1));
            }
        }
        return ans;
    }
};
