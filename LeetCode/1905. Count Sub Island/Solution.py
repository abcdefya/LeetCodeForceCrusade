class Solution:
    def countSubIslands(self, grid1: list[list[int]], grid2: list[list[int]]) -> int:
        m, n = len(grid2), len(grid2[0])
        count = 0
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        for i in range(m):
            for j in range(n):
                if grid2[i][j] == 0: 
                    continue
                
                grid2[i][j] = 0
                stack = [(i, j)]
                is_sub = True

                while stack:
                    x, y = stack.pop()

                    if grid1[x][y] == 0:
                        is_sub = False

                    for dx, dy in directions:
                        nx, ny = x + dx, y + dy

                        if 0 <= nx < m and 0 <= ny < n and grid2[i][j] == 1:
                            grid2[i][j] = 0
                            stack.append((nx, ny))

                if is_sub:
                    count += 1

        return count