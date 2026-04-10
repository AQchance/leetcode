#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int ans = 0;
        std::unordered_map<int, int> my_map;
        my_map[0] = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (my_map.contains(sum - k)) {
                ans += my_map[sum - k];
            }
            if (my_map.contains(sum)) {
                my_map[sum]++;
            } else {
                my_map[sum] = 1;
            }
        }
        return ans;
    }
};

int main()
{
    std::vector<int> nums { 1 };
    int k = 0;
    Solution sol;
    sol.subarraySum(nums, k);
}
