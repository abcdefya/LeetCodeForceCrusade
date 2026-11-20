class Solution:
    def countStudents(self, students: list[int], sandwiches: list[int])-> int:
        queue = deque(students)
        top = 0
        skip = 0

        while queue and skip < len(queue):
            if sandwiches[top] == queue[0]:
                top += 1
                queue.popleft()
                skip = 0
            else:
                queue.append(queue.popleft())
                skip += 1

        return len(queue)
