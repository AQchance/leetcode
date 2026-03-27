#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct Frequency {
    int num;
    int frequency;
    bool operator<(const Frequency& other) const
    {
        return this->frequency < other.frequency;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        std::vector<int> ans;
        std::unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.contains(nums[i])) {
                m[nums[i]]++;
            } else {
                m[nums[i]] = 1;
            }
        }
        std::priority_queue<Frequency> pq;
        for (const auto& item : m) {
            pq.push(Frequency(item.first, item.second));
        }
        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().num);
            pq.pop();
        }
        return ans;
    }
};
