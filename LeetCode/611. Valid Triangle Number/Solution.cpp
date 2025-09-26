#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int triangleNumber(vector<int>& nums) {
            int n = (int)nums.size();
            
            // Sort the array so that we can use the two pointer trick
            sort(nums.begin(), nums.end());
            long long ans = 0;

            for (int k = n - 1; k >= 2; k--) {
                int i = 0, j = k - 1;
                while(i < j) {
                // Check the triangle inequality for sorted sides:
                // a = nums[i], b = nums[j], c = nums[k] (a <= b <= c)
                // Only need to check a + b > c
                    if (nums[i] + nums[j] > nums[k]){
                    // If nums[i] +_ nums[j] > nums[k], then for every index t in [i, j - 1],
                    // nums[t] >= nums[i], so nums[t] + nums[j] > nums[k]
                    // Therefor, (j - i) pairs are valid with the current j.
                    ans += (j - i);
                    // Move j left to try a smaller midldle side and find more pairs.
                    j--;

                    } else {
                        // Sum is too small, move i right to increase it
                        i++;
                    }
                }
            }
            return (int)ans;
        }
};