class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1000000007;
        sort(nums.begin(), nums.end()); // Sort the array
        int n = nums.size();
        long long result = 0;
        
        // Precompute powers of 2
        vector<long long> pow2(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }
        
        // Two-pointer technique
        int left = 0, right = n - 1;
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                result = (result + pow2[right - left]) % MOD;
                ++left;
            } else {
                --right;
            }
        }
        
        return result;
    }
};