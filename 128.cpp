#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int ans = 0;
        std::unordered_set<int> my_set;
        for (auto num : nums) {
            my_set.insert(num);
        }
        for (auto num : my_set) {
            if (my_set.contains(num - 1)) {
                continue;
            } else {
                int res = num;
                int cnt = 0;
                while (my_set.contains(res)) {
                    cnt++;
                    res++;
                }
                ans = std::max(cnt, ans);
            }
        }
        return ans;
    }
};
