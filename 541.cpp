#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k)
    {
        int index = 0;
        while (index < s.size()) {
            if (index + k >= s.size()) {
                assist_func(s, index, s.size() - 1);
            } else {
                assist_func(s, index, index + k - 1);
            }
            index += 2 * k;
        }
        return s;
    }
    void assist_func(string& s, int left, int right)
    {
        while (left < right) {
            std::swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
