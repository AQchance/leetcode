#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

// NOTE: 此解法栈溢出了
// struct Position {
//     Position(int row, int col)
//         : row(row)
//         , col(col)
//     {
//     }
//     int row;
//     int col;
//     bool operator<(const Position& position) const
//     {
//         if (row < position.row) {
//             return true;
//         } else if (row == position.row) {
//             return col < position.col;
//         } else {
//             return false;
//         }
//     }
// };
//
// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid)
//     {
//         std::set<Position> s;
//         std::map<Position, int> m;
//         int max_row = grid.size();
//         int max_col = grid[0].size();
//         for (size_t i = 0; i < max_row; i++) {
//             for (size_t j = 0; j < max_col; j++) {
//                 if (grid[i][j] == '1') {
//                     m.insert(std::make_pair<Position, int>(Position(i, j), 1));
//                 }
//             }
//         }
//         int cnt = 0;
//         while (!m.empty()) {
//             mark_island(m, m.begin()->first, max_row, max_col);
//             for (auto iter = m.begin(); iter != m.end();) {
//                 if (iter->second == 0) {
//                     iter++;
//                 } else {
//                     iter = m.erase(iter);
//                 }
//             }
//             cnt++;
//         }
//         return cnt;
//     }
//     void mark_island(std::map<Position, int>& m, const Position& position, int max_row, int max_col)
//     {
//         m[position] = 0;
//         if (position.row > 0 && m.find(Position(position.row - 1, position.col)) != m.end()) {
//             Position tmp(position.row - 1, position.col);
//             mark_island(m, tmp, max_row, max_col);
//         }
//         if (position.col > 0 && m.find(Position(position.row, position.col - 1)) != m.end()) {
//             Position tmp(position.row, position.col - 1);
//             mark_island(m, tmp, max_row, max_col);
//         }
//         if (position.row < max_row - 1 && m.find(Position(position.row + 1, position.col)) != m.end()) {
//             Position tmp(position.row + 1, position.col);
//             mark_island(m, tmp, max_row, max_col);
//         }
//         if (position.col < max_col - 1 && m.find(Position(position.row, position.col + 1)) != m.end()) {
//             Position tmp(position.row, position.col + 1);
//             mark_island(m, tmp, max_row, max_col);
//         }
//     }
// };
