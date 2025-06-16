#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int subArraySum(vector<int>& nums, int k) {
        unordered_map <long long, int> sumFreq{{0, 1}};
        int count = 0;
        long long sum = 0;
        for(int num : nums){
            sum += num;

            if(sumFreq.count(sum - k)) {
                count += sumFreq[sum-k];
            }
            sumFreq[sum]++;
        }

        return count;
    }
}