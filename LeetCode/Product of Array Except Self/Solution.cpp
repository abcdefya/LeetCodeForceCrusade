#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size();
            vector<int> ans(n, 1);

            int left = 1;
            for(int i = 0; i < n; ++i) {
                ans[i] *= left;
                left *= nums[i];
            }

            int right = 1;
            for (int j = n - 1; j >= 0; --j){
                ans[j] *= right;
                right *= nums[j];
            }

            return ans;
        }
};