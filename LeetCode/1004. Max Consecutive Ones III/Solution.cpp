#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int n = (int)nums.size();
            int left = 0, zeros = 0, best = 0;

            for (int r = 0; r < n; ++r) {
                if (nums[r] == 0) ++zeros;
                while (zeros > k) {
                    if (nums[left] == 0) --zeros;
                    ++left;
                }
                best = max(best, r - left + 1);
            }
            return best;
        }
};