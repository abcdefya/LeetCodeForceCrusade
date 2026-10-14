class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> r_q;
        int fresh = 0;

        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (grid[x][y] == 2) r_q.push({x, y});
                else if (grid[x][y] == 1) fresh++;
            }
        }

        vector<pair<int,int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int minutes = 0;

        while (!r_q.empty() && fresh > 0) {
            int sz = r_q.size();
            for (int i = 0; i < sz; i++) {
                auto [rx, ry] = r_q.front();
                r_q.pop();

                for (auto [dx, dy] : directions) {
                    int nx = rx + dx, ny = ry + dy;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        fresh--;
                        r_q.push({nx, ny});
                    }
                }
            }
            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};