#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int i = 0, j = 0;
        int num = 1;
        int times = n * n;
        // 1,2,3,4分别表示右，下，左，上
        int flag = 1;
        while (num <= times) {
            ans[i][j] = num;
            num++;
            if (flag == 1) {
                if (j + 1 >= n || ans[i][j + 1] != 0) {
                    flag = 2;
                    i++;
                } else {
                    j++;
                }
            } else if (flag == 2) {
                if (i + 1 >= n || ans[i + 1][j] != 0) {
                    flag = 3;
                    j--;
                } else {
                    i++;
                }
            } else if (flag == 3) {
                if (j - 1 < 0 || ans[i][j - 1] != 0) {
                    flag = 4;
                    i--;
                } else {
                    j--;
                }
            } else if (flag == 4) {
                if (i - 1 < 0 || ans[i - 1][j] != 0) {
                    flag = 1;
                    j++;
                } else {
                    i--;
                }
            }
        }
        return ans;
    }
};
