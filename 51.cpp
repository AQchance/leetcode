#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    std::vector<std::vector<std::string>> ans;
    std::vector<std::pair<int, int>> path;

public:
    vector<vector<string>> solveNQueens(int n)
    {
        std::vector<std::vector<int>> used(n, std::vector<int>(n, 0));
        helper(n, used, 0, 0);
        return ans;
    }
    void helper(int n, vector<vector<int>>& used, int row_start, int col_start)
    {
        if (n == 0) {
            std::string tmp;
            for (int i = 0; i < path.size(); i++) {
                tmp.push_back('.');
            }
            std::vector<std::string> real_path(path.size(), tmp);
            for (int i = 0; i < path.size(); i++) {
                int row = path[i].first;
                int col = path[i].second;
                real_path[row][col] = 'Q';
            }
            ans.push_back(real_path);
            return;
        }
        for (int i = 0; i < used.size(); i++) {
            for (int j = 0; j < used.size(); j++) {
                if (i * used.size() + j < row_start * used.size() + col_start) {
                    continue;
                }
                if (used[i][j] > 0) {
                    continue;
                }
                path.push_back(std::pair(i, j));
                fill(n, 0, used, i, j);
                if (j != used.size() - 1) {
                    helper(n - 1, used, i, j + 1);
                } else {
                    helper(n - 1, used, i + 1, 0);
                }
                fill(0, n, used, i, j);
                path.pop_back();
            }
        }
    }
    // 把目标数值target替换成n
    void fill(int n, int target, std::vector<std::vector<int>>& used, int row, int col)
    {
        // 首先填充一整行
        for (int i = 0; i < used.size(); i++) {
            if (used[row][i] == target) {
                used[row][i] = n;
            }
        }
        // 然后填充一整列
        for (int i = 0; i < used.size(); i++) {
            if (used[i][col] == target) {
                used[i][col] = n;
            }
        }
        // 然后填充斜向左上的
        for (int i = row, j = col; i >= 0 && j >= 0 && i < used.size() && j < used.size();) {
            if (used[i][j] == target) {
                used[i][j] = n;
            }
            i--;
            j--;
        }
        // 然后填充斜向右下的
        for (int i = row, j = col; i >= 0 && j >= 0 && i < used.size() && j < used.size();) {
            if (used[i][j] == target) {
                used[i][j] = n;
            }
            i++;
            j++;
        }
        // 然后填充斜向右上的
        for (int i = row, j = col; i >= 0 && j >= 0 && i < used.size() && j < used.size();) {
            if (used[i][j] == target) {
                used[i][j] = n;
            }
            i--;
            j++;
        }
        // 然后填充斜向左下的
        for (int i = row, j = col; i >= 0 && j >= 0 && i < used.size() && j < used.size();) {
            if (used[i][j] == target) {
                used[i][j] = n;
            }
            i++;
            j--;
        }
    }
};
