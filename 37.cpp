#include <filesystem>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        // 用来记录第n行数字是否被用过了。
        std::vector<std::vector<bool>> row_used(board.size(), std::vector<bool>(board.size() + 1, false));
        std::vector<std::vector<bool>> col_used(board.size(), std::vector<bool>(board.size() + 1, false));
        std::vector<std::vector<bool>> block_used(board.size(), std::vector<bool>(board.size() + 1, false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    row_used[i][num] = true;
                    col_used[j][num] = true;
                    block_used[get_block_number(i, j)][num] = true;
                }
            }
        }
        helper(board, 0, 0, row_used, col_used, block_used);
    }
    bool helper(vector<vector<char>>& board, int row, int col, vector<vector<bool>>& row_used, vector<vector<bool>>& col_used, vector<vector<bool>>& block_used)
    {
        if (row >= board.size() || col >= board.size()) {
            return true;
        }
        if (board[row][col] != '.') {
            if (col == board.size() - 1) {
                return helper(board, row + 1, 0, row_used, col_used, block_used);
            } else {
                return helper(board, row, col + 1, row_used, col_used, block_used);
            }
        }
        for (int i = 1; i <= board.size(); i++) {
            int block_number = get_block_number(row, col);
            if (!row_used[row][i] && !col_used[col][i] && !block_used[block_number][i]) {
                row_used[row][i] = true;
                col_used[col][i] = true;
                block_used[block_number][i] = true;

                board[row][col] = i + '0';

                bool flag = false;
                if (col == board.size() - 1) {
                    flag = helper(board, row + 1, 0, row_used, col_used, block_used);
                } else {
                    flag = helper(board, row, col + 1, row_used, col_used, block_used);
                }
                if (flag == true) {
                    return true;
                }
                board[row][col] = '.';

                row_used[row][i] = false;
                col_used[col][i] = false;
                block_used[block_number][i] = false;
            }
        }
        return false;
    }
    int get_block_number(int row, int col)
    {
        int row_number = row / 3;
        int col_number = col / 3;
        return row_number * 3 + col_number;
    }
};
