#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        std::unordered_set<int> my_set1;
        std::unordered_set<int> my_set2;
        for (const auto& num : nums1) {
            my_set1.insert(num);
        }
        for (const auto& num : nums2) {
            if (my_set1.contains(num)) {
                my_set2.insert(num);
            }
        }
        return std::vector<int>(my_set2.begin(), my_set2.end());
    }
};
