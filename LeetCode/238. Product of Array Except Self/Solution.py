class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        answer = [1] * n
        # First pas: Compute the prefix products
        for i in range(1, n):
            answer[i] = answer[i-1] * nums[i-1]
        
        # Second pass: Compute the suffix products on the fly
        R = 1
        for i in range(n-1, -1, -1):
            answer[i] *= R
            R *= nums[i]
            
        return answer