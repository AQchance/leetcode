#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        std::vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<std::vector<bool>> used(m, std::vector<bool>(n, false));
        int cnt = 0;
        int row = 0, col = 0;
        int flag = 0;
        while (cnt < m * n) {
            ans.push_back(matrix[row][col]);
            used[row][col] = true;
            if (flag == 0) {
                if (col < n - 1 && !used[row][col + 1]) {
                    col++;
                } else {
                    row++;
                    flag = 1;
                }
            } else if (flag == 1) {
                if (row < m - 1 && !used[row + 1][col]) {
                    row++;
                } else {
                    col--;
                    flag = 2;
                }
            } else if (flag == 2) {
                if (col > 0 && !used[row][col - 1]) {
                    col--;
                } else {
                    row--;
                    flag = 3;
                }
            } else {
                if (row > 0 && !used[row - 1][col]) {
                    row--;
                } else {
                    col++;
                    flag = 0;
                }
            }
            cnt++;
        }
        return ans;
    }
};
