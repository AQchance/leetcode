#include <queue>
#include <vector>

using namespace std;

struct Info {
    int row;
    int col;
    int time;
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int cnt = 0;
        std::queue<Info> q;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    cnt++;
                } else if (grid[i][j] == 2) {
                    q.push(Info(i, j, 0));
                }
            }
        }
        int ans = 0;
        while (cnt > 0 && !q.empty()) {
            int cur_time = q.front().time;
            while (!q.empty() && q.front().time == cur_time) {
                int row = q.front().row;
                int col = q.front().col;
                q.pop();
                grid[row][col] = 0;
                if (row > 0 && grid[row - 1][col] == 1) {
                    grid[row - 1][col] = 2;
                    q.push(Info(row - 1, col, cur_time + 1));
                    cnt--;
                }
                if (row < m - 1 && grid[row + 1][col] == 1) {
                    grid[row + 1][col] = 2;
                    q.push(Info(row + 1, col, cur_time + 1));
                    cnt--;
                }
                if (col > 0 && grid[row][col - 1] == 1) {
                    grid[row][col - 1] = 2;
                    q.push(Info(row, col - 1, cur_time + 1));
                    cnt--;
                }
                if (col < n - 1 && grid[row][col + 1] == 1) {
                    grid[row][col + 1] = 2;
                    q.push(Info(row, col + 1, cur_time + 1));
                    cnt--;
                }
            }
            ans = cur_time + 1;
        }
        if (cnt == 0) {
            return ans;
        } else {
            return -1;
        }
    }
};
