#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end())
        for (int i = (int)nums.size() - 1; i >=2; --i) {
            int a = nums[i - 2], b = nums[i - 1], c = nums[i];
                // For sorted size a <= b <= c, it's sufficient to check a + b > c
                if ((long long)a + b > c) {
                    return a + b + c;
                }

        }

        return 0; // No case found
    }
}