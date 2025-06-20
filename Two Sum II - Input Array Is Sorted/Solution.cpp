#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mp;
        vector<int> res;
        
        for (int i = 0; i < numbers.size(); ++i) {
            if (mp.count(target - numbers[i])) {
                res.push_back(mp[target - numbers[i]] + 1); // 1-based
                res.push_back(i + 1);                       // 1-based
                return res; 
            }
            mp[numbers[i]] = i;
        }
        
        return res;
    }

    vector<int> twoSumWithTwoPointers(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        
        while(left < right) {
            int sum = numbers[left] + numbers[right];
            if(sum == target) {
                return { left + 1, right + 1 };
            } else if(sum > target) {
                right --;
            } else {
                left ++;
            }
        }
        return {};
    }
};