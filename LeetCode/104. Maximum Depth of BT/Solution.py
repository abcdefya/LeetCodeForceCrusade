from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# DFS, awesome
class Solution:
    def maxDepth(self, root: TreeNode | None):
        if not root: # Base
            return 0
        left = self.maxDepth(root.left)
        right = self.maxDepth(root.right)
        return 1 + max(left, right)

# BFS
# class Solution:
#     def maxDepth(self, root: TreeNode | None):
#         if not root:
#             return 0

#         q = deque([root])
#         depth = 0
#         while(q):

#             for _ in len(q):
#                 node = q.popleft()
#                 if (node.left):
#                     q.append(node.left)
#                 if (node.right):
#                     q.append(node.right)
#         depth += 1

#         return depth