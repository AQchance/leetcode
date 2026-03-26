#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
        std::unordered_map<int, int> m1;
        std::unordered_map<int, int> m2;
        int cnt = 0;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (m1.contains(nums1[i] + nums2[j])) {
                    m1[nums1[i] + nums2[j]]++;
                } else {
                    m1[nums1[i] + nums2[j]] = 1;
                }
            }
        }
        for (int i = 0; i < nums3.size(); i++) {
            for (int j = 0; j < nums4.size(); j++) {
                if (m2.contains(nums3[i] + nums4[j])) {
                    m2[nums3[i] + nums4[j]]++;
                } else {
                    m2[nums3[i] + nums4[j]] = 1;
                }
            }
        }
        for (const auto& item : m1) {
            if (m2.contains(-item.first)) {
                cnt += item.second * m2[-item.first];
            }
        }
        return cnt;
    }
};
