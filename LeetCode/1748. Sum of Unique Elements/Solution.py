class Solution:
    def sumOfUnique(self, nums: list[int]) -> int:
        count = {}
        for x in nums:
            count[x] = count.get(x, 0) + 1

        total = 0
        for key, value in count.items():
            if value == 1:
                total += key
        return total   