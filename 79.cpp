#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    std::string path;

public:
    bool exist(vector<vector<char>>& board, string word)
    {
        int m = board.size(), n = board[0].size();
        std::vector<std::vector<bool>> used(m, std::vector<bool>(n, false));
        return helper(board, word, 0, 0, used, 0);
    }
    bool helper(vector<vector<char>>& board, const string& word, int row, int col, vector<vector<bool>>& used, int index)
    {

        for (; row < board.size() && col < board[0].size();) {
            bool flag = dfs(board, word, row, col, used, index);
            if (flag) {
                return true;
            }
            if (col == board[0].size() - 1) {
                col = 0;
                row++;
            } else {
                col++;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, const string& word, int row, int col, vector<vector<bool>>& used, int index)
    {
        if (index >= word.size()) {
            return true;
        }
        if (row >= board.size() || col >= board[0].size()) {
            return false;
        }
        if (row < 0 || col < 0) {
            return false;
        }
        if (board[row][col] == word[index] && !used[row][col]) {
            index++;
            used[row][col] = true;
            bool flag = false;
            flag = dfs(board, word, row - 1, col, used, index) || dfs(board, word, row + 1, col, used, index) || dfs(board, word, row, col - 1, used, index) || dfs(board, word, row, col + 1, used, index);
            if (flag) {
                return true;
            }
            used[row][col] = false;
            index--;
        }
        return false;
    }
};

int main()
{
    std::vector<std::vector<char>> board { { 'a', 'b' }, { 'c', 'd' } };
    std::string word = "abcd";
    Solution sol;
    sol.exist(board, word);
}
