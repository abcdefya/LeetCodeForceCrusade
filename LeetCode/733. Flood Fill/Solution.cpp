class Solution {
public:
    int m, n, original, newColor;
    vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void dfs(vector<vector<int>>& image, int x, int y) {
        image[x][y] = newColor;
        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && image[nx][ny] == original)
                dfs(image, nx, ny);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size(); n = image[0].size();
        original = image[sr][sc];
        newColor = color;
        if (original == color) return image;
        dfs(image, sr, sc);
        return image;
    }
};