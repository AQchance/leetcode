#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        std::unordered_map<char, int> m;
        for (const auto ch : magazine) {
            if (m.contains(ch)) {
                m[ch]++;
            } else {
                m[ch] = 1;
            }
        }
        bool flag = true;
        for (const auto ch : ransomNote) {
            if (m.contains(ch)) {
                m[ch]--;
                if (m[ch] == 0) {
                    auto iter = m.find(ch);
                    m.erase(iter);
                }
            } else {
                flag = false;
                break;
            }
        }
        return flag;
    }
};
