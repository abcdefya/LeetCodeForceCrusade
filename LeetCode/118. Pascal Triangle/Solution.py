class Solution:
    def generate(self, numRows: int) -> list[list[int]]:
        arr = []
        for i in range(numRows):
            arr.append((i+1)*[1])
            for j in range(1, numRows):
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j]

        return arr