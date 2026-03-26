#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0) {
            return 0;
        }
        vector<int> next = get_next(needle);
        int index = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while (index > 0 && haystack[i] != needle[index]) {
                index = next[index - 1];
            }
            if (haystack[i] == needle[index]) {
                index++;
            }
            if (index == needle.size()) {
                return i - index + 1;
            }
        }
        return -1;
    }
    vector<int> get_next(const string& p)
    {
        std::vector<int> next(p.size());
        next[0] = 0;
        for (int i = 1; i < next.size(); i++) {
            int index = i - 1;
            while (index > 0 && p[index] != p[i]) {
                index = next[index - 1];
            }
            if (p[index] == p[i]) {
                next[i] = index + 1;
            } else {
                next[i] = 0;
            }
        }
        return next;
    }
};
