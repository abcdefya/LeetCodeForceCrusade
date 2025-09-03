class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        result = []
        for i in range(len(nums)):
            x = abs(nums[i])
            idx = x - 1
            if nums[idx] < 0:
                result.append(x)
            else:
                nums[idx] = -nums[idx]
        return result