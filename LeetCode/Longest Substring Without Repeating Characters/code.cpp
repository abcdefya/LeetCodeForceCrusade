#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int left = 0;
        unordered_map<char, int> char_pos;

        for (int right = 0; right < s.length(); ++right) {
            if (char_pos.count(s[right]) && char_pos[s[right]] >= left) {
                // Move left pointer to the position after the last occurrence
                left = char_pos[s[right]] + 1;
            }
            // Update the position of the current character
            char_pos[s[right]] = right;
            // Update maxLen with the current window size
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};