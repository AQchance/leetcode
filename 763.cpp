#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// NOTE: 自己的做法，做的有点麻烦了，实际上不需要区间合并，直接贪心。
// struct Info {
//     int start;
//     int end;
// };
//
// bool cmp(Info& a, Info& b)
// {
//     return a.start < b.start;
// }
//
// class Solution {
// public:
//     vector<int> partitionLabels(string s)
//     {
//         std::unordered_map<char, Info> my_map;
//         for (int i = 0; i < s.size(); i++) {
//             if (my_map.contains(s[i])) {
//                 my_map[s[i]].end = i;
//             } else {
//                 my_map[s[i]] = Info(i, i);
//             }
//         }
//         std::vector<Info> all_ranges;
//         for (auto item : my_map) {
//             all_ranges.push_back(item.second);
//         }
//         std::sort(all_ranges.begin(), all_ranges.end(), cmp);
//         std::vector<Info> merged_ranges;
//         merged_ranges.push_back(all_ranges[0]);
//         for (int i = 1; i < all_ranges.size(); i++) {
//             if (merged_ranges.back().end < all_ranges[i].start) {
//                 merged_ranges.push_back(all_ranges[i]);
//             } else {
//                 merged_ranges.back().end = std::max(merged_ranges.back().end, all_ranges[i].end);
//             }
//         }
//         std::vector<int> ans;
//         for (int i = 0; i < merged_ranges.size(); i++) {
//             ans.push_back(merged_ranges[i].end - merged_ranges[i].start + 1);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> partitionLabels(string s)
    {
        std::vector<int> ans;
        int last[26] = { 0 };
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }
        int end = 0;
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i < end) {
                end = std::max(end, last[s[i] - 'a']);
            } else if (i == end) {
                if (end == last[s[i] - 'a']) {
                    ans.push_back(end - start + 1);
                    end++;
                    start = end;
                } else {
                    end = last[s[i] - 'a'];
                }
            }
        }
        return ans;
    }
};
