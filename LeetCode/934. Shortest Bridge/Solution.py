
class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        n = len(grid)
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        q = deque()

        si, sj = next((i, j) for i in range(n) for j in range(n) if grid[i][j] == 1)
        grid[si][sj] = 2
        stack = [(si, sj)]
        while stack:
            x, y = stack.pop()
            q.append((x, y))                    
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < n and grid[nx][ny] == 1:
                    grid[nx][ny] = 2
                    stack.append((nx, ny))

        # Bước 2: BFS nhiều nguồn, lan ra mặt nước theo từng tầng
        steps = 0
        while q:
            for _ in range(len(q)):
                x, y = q.popleft()
                for dx, dy in directions:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < n and 0 <= ny < n:
                        if grid[nx][ny] == 1:       
                            return steps
                        if grid[nx][ny] == 0:       
                            grid[nx][ny] = 2
                            q.append((nx, ny))
            steps += 1
        return -1