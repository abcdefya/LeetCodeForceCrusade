#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            unordered_map<int, int> um_nums;
            
            for(int i = 0; i < nums.size(); ++i) {
                if(um_nums.count(nums[i])){
                    if(i - um_nums[nums[i]] <= k){
                        return true;
                    }
                }
                um_nums[nums[i]] = i;
            }
            return false;
        }
};