from collections import deque
from typing import List

## DFS
class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        isVisited = n * [False]
        count = 0

        def dfs(cur):
            isVisited[cur] = True
            for i in range(n):
                if isConnected[cur][i] == 1 and not isVisited[i]:
                    dfs(i)

        for c in range(n):
            if not isVisited[c]:
                count += 1
                dfs(c)

        return count



## BFS
# class Solution:
#     def findCircleNum(self, isConnected: List[List[int]]) -> int:
#         n = len(isConnected)
#         isVisited = n * [False]
#         count = 0
        
#         for c in range(n):
#             if isVisited[c]:
#                 continue
#             count += 1
#             isVisited[c] = True
#             q = deque([c])

#             while q:
#                 cur = q.popleft()

#                 for i in range(n):
#                     if isConnected[cur][i] == 1 and not isVisited[i]:
#                         isVisited[i] = True
#                         q.append(i)

#         return count