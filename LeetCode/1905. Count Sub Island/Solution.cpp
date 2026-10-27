class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size(), n = grid2[0].size();
        vector<pair<int,int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] != 1) continue;
                bool is_sub = true;
                grid2[i][j] = 0;
                vector<pair<int,int>> st = {{i, j}};
                while (!st.empty()) {
                    auto [x, y] = st.back();
                    st.pop_back();
                    if (grid1[x][y] == 0) is_sub = false;
                    for (auto [dx, dy] : directions) {
                        int nx = x + dx, ny = y + dy;
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid2[nx][ny] == 1) {
                            grid2[nx][ny] = 0;
                            st.push_back({nx, ny});
                        }
                    }
                }
                if (is_sub) count++;
            }
        }
        return count;
    }
};