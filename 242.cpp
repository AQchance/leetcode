#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size()) {
            return false;
        }
        std::unordered_map<char, int> hash_map;
        for (const auto& ch : s) {
            if (hash_map.contains(ch)) {
                hash_map[ch]++;
            } else {
                hash_map[ch] = 1;
            }
        }
        bool flag = true;
        for (const auto& ch : t) {
            if (hash_map.contains(ch)) {
                hash_map[ch]--;
                if (hash_map[ch] == 0) {
                    auto iter = hash_map.find(ch);
                    hash_map.erase(iter);
                }
            } else {
                flag = false;
                break;
            }
        }
        return flag;
    }
};
