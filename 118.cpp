#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        int n = 1;
        std::vector<std::vector<int>> ans;
        ans.push_back(std::vector<int> { 1 });
        while (n < numRows) {
            int left = -1, right = 0;
            std::vector<int>& pre = ans.back();
            int size = ans.size();
            std::vector<int> tmp;
            for (; left < size; left++, right++) {
                int sum = 0;
                if (left >= 0) {
                    sum += pre[left];
                }
                if (right < size) {
                    sum += pre[right];
                }
                tmp.push_back(sum);
            }
            ans.push_back(tmp);
            n++;
        }
        return ans;
    }
};
