#include <bits/stdc++.h>
using namespace std;

class Solution{
    public: 
        vector<int> findDuplicates(vector<int>& nums){
            vector<int> result;
            for(int i = 0; i < nums.size(); ++i){
                int x = abs(nums[i]);
                int idx = x - 1;
                if(nums[idx] < 0) {
                    result.push_back(x);
                } else {
                    nums[idx] = -nums[idx];
                }
            }
            return result;
        }
}