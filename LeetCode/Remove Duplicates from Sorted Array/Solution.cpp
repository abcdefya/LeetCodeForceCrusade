#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if(nums.empty()) return 0;

            // Using two pointers
            int write = 1;
            for(int read = 0; read < nums.size(); ++read) {
                if (nums[read] != nums[read - 1]) {
                    nums[write] = nums[read];
                    write++;
                }
            }

            return write;
        }
}