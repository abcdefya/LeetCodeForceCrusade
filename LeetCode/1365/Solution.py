class Solution:
    def smallerNumbersThanCurrent(self, nums: list[int]) -> list[int]:
        MAX_VAL = 100
        count = [0] * (MAX_VAL + 2)

        for x in nums:
            count[x + 1] += 1

        for i in range(1, len(count)):    
            count[i] += count[i - 1]

        return [count[x] for x in nums]