class Solution:
    def findOrder(self, numCourses: int, prerequisites: list[list[int]]) -> list[int]:
        graph = [[] for _ in range(numCourses)]
        indeg = [0] * numCourses

        for a, b in prerequisites:
            graph[b].append(a)
            indeg[a] +=1

        queue = deque(i for i in range(numCourses) if indeg[i] == 0)
        order = []

        while queue:
            course = queue.popleft()
            order.append(course)

            for next in graph[course]:
                indeg[next] -= 1
                if indeg[next] == 0:
                    queue.append(next)

        return order if len(order) == numCourses else []