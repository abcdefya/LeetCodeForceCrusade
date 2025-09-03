from typing import List
class Solution:
    def diagonalSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        sum = 0
        for i in range(n):
            sum += matrix[i][i]
            sum += matrix[i][n-i-1]
        if n % 2 == 1:
            sum -= matrix[n//2][n//2]
        return sum