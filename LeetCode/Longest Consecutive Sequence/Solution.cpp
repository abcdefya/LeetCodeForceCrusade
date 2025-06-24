#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 1;
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;


        for(int num : numSet) {
            // If current number is the begining of a consecutive range of numbers
            if(numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                while(numSet.find(currentNum + 1) != numSet.end()){ // If the next number appear in set
                    currentNum++;
                    currentStreak++;
                }

                longest = max(longest, currentStreak);
            }
        }
        return longest;
    }
};