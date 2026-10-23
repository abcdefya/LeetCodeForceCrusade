class Solution {
public:
    int m, n
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int dfs(vector<vector<int>>& grid, int x, int y) {
        grix[x][y] = 0
        area = 1

        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                area += dfs(grid, nx, ny)
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int max_area = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    max_area = max(max_area, dfs(grid, i, j));
        return max_area;
    }
};