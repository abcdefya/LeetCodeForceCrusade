class Solution:
    def floodFill(self, image: list[list[int]], sr: int, sc: int, color: int) -> list[list[int]]:
        m, n = len(image), len(image[0])
        org = image[sr][sc]
        if org == color:          # màu đã giống, không cần tô
            return image
        
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        def dfs(x, y):
            image[x][y] = color

            for dx, dy in directions:
                nx, ny = x + dx, y + dy

                if 0 <= nx < m and 0 <= ny < n and image[nx][ny] == org:
                    dfs(nx, ny)

        dfs(sr, sc)
        return image