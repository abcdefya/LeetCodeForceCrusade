from collections import deque
from typing import List

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        r_q  = deque()
        fresh = 0

        for i in range(m):
            for j in range(n):
                if (grid[i][j] == 2):
                    r_q.append((i, j))
                elif (grid[i][j] == 1):
                    fresh += 1
            
        min = 0
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        while r_q and fresh > 0:

            for _ in len(r_q):
                rx, ry = r_q.popleft()

                for dx, dy in directions:
                    nx, ny = nx + dx, ny + dy

                    if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] == 1:
                        grid[nx][ny] == 2
                        fresh -= 1
                        r_q.append((nx, ny))
            min += 1

        return min if fresh == 0 else -1