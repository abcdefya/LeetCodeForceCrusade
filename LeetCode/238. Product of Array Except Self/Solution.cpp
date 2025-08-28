#include <bits/stdc++.h>
using namespace std;

class Solution {
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> answer(n, 1);

        // First pass: Compute the prefix products
        for (int i = 1; i < n; i++) {
            answer[i] = answer[i-1] * nums[i-1];
        }

        // Second pass: Compute the suffix products on the fly
        int R = 1;
        for (int i = n-1; i >= 0; i--) {
            answer[i] *= R;
            R *= nums[i];
        }

        return answer;
    }
}