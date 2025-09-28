from typing import List

class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        # Sort ascending so we can check triples from the largest side
        nums.sort()
        # Trarvese from the end; check consecutive triplses (i-2, i-1, i)
        for i in range(len(nums) - 1, 1, -1):
            a, b, c = nums[i - 2], nums[i - 1], nums[i]
            if a + b > c:
                return a + b + c
        
        return 0