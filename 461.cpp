#include <vector>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y)
    {
        int ans = 0;
        x = x ^ y;
        while (x > 0) {
            if ((x & 1) == 1) {
                ans++;
            }
            x = x >> 1;
        }
        return ans;
    }
};
