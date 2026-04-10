#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// NOTE: 这个方法是模拟的方法，利用了贪心，但是实际上不是最优，这个题目可以用数学方法来破解。
// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n)
//     {
//         int ans = 0;
//         vector<int> fre(26, 0);
//         for (int i = 0; i < tasks.size(); i++) {
//             fre[tasks[i] - 'A']++;
//         }
//         std::priority_queue<int> pq;
//         for (int i = 0; i < 26; i++) {
//             if (fre[i] != 0) {
//                 pq.push(fre[i]);
//             }
//         }
//         while (!pq.empty()) {
//             std::vector<int> tmp;
//             for (int i = 0; i < n + 1; i++) {
//                 if (!pq.empty()) {
//                     int num = pq.top();
//                     pq.pop();
//                     num--;
//                     if (num > 0) {
//                         tmp.push_back(num);
//                     }
//                     ans++;
//                 } else if (pq.empty() && !tmp.empty()) {
//                     ans++;
//                 } else {
//                     break;
//                 }
//             }
//             for (const auto num : tmp) {
//                 pq.push(num);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        int ans = 0;
        int max_fre = 0;
        int max_fre_count = 0;
        std::unordered_map<char, int> my_map;
        for (int i = 0; i < tasks.size(); i++) {
            if (my_map.contains(tasks[i])) {
                my_map[tasks[i]]++;
            } else {
                my_map[tasks[i]] = 1;
            }
            max_fre = std::max(max_fre, my_map[tasks[i]]);
        }
        for (const auto item : my_map) {
            if (item.second == max_fre) {
                max_fre_count++;
            }
        }
        int slot_num = (max_fre - 1) * (n + 1) + max_fre_count;
        ans = tasks.size();
        ans = std::max(ans, slot_num);
        return ans;
    }
};
