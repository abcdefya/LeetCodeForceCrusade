class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> out(m, vector<int>(n, -1));
        
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    out[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            
            for(auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && out[nx][ny] == -1) {
                    out[nx][ny] = out[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return out;
    }
};