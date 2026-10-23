# BFS
# from queue import deque
class Solution:
    def maxAreaOfIsland(self, grid: list[list[int]]) -> int:
        m, n = len(grid), len(grid[0])
        maxArea = 0
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    grid[i][j] = 0
                    q = deque([(i, j)])
                    area = 0
                    while q:
                        x, y = q.popleft()
                        area += 1
                        for dx, dy in directions:
                            nx, ny = x + dx, y + dy

                            if (0 <= nx < m and 0 <= ny < n and grid[nx][ny] == 1):
                                grid[nx][ny] = 0
                                q.append((nx, ny))
                maxArea = max(area, maxArea)
        return maxArea


#  DFS
# class Solution:
#     def maxAreaOfIsland(self, grid: list[list[int]]) -> int:
#         m, n = len(grid), len(grid[0])
#         maxArea = 0
#         directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

#         def dfs(x, y):
#             grid[x][y] = 0
#             area = 1

#             for dx, dy in directions:
#                 nx, ny = x + dx, y + dy

#                 if 0 <= nx < m and 0 <= ny < m and grid[nx][ny] == 1:
#                     area += dfs(nx, ny)

#             return area

#         for i in range(m):
#             for j in range(n):
#                 if grid[i][j] == 1:
#                     maxArea = max(maxArea, dfs(i, j))
#         return maxArea