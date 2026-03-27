#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s)
    {
        bool flag = false;
        int size = 1;
        for (; size < s.size(); size++) {
            if (s.size() % size == 0) {
                for (int i = 0; i < s.size(); i++) {
                    if (s[i] != s[i % size]) {
                        break;
                    }
                    if (i == s.size() - 1) {
                        flag = true;
                    }
                }
                if (flag == true) {
                    break;
                }
            }
        }
        return flag;
    }
};
