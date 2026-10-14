from collections import deque
from typing import List

class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        isVisited = n * [False]
        count = 0
        
        for c in range(n):
            if isVisited[c]:
                continue
            count += 1
            isVisited[c] = True
            q = deque([c])

            while q:
                cur = q.popleft()

                for i in range(n):
                    if isConnected[cur][i] == 1 and not isVisited[i]:
                        isVisited[i] = True
                        q.append(i)

        return count