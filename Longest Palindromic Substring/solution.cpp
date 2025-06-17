#include <bits/stdc++.h>
using namespace std;

class Solution{
    public: 
        string longestPalindrome(string s) {
            int n = s.length();

            if(n==0) return "";

            int start = 0, maxLen = 1;

            // lambda function to extract palindrome substring
            auto expandAroundCenter = [&](int left, int right) {
                while (left >= 0 && right < n && s[left] == s[right]) {
                    int currentLen = right - left + 1;
                    if (currentLen > maxLen) {
                        maxLen = currentLen;
                        start = left;
                    }
                    --left;
                    ++right;
                }
            };

            for (int i = 0; i < n; ++i) {
                expandAroundCenter(i, i);     // Odd length palindrome
                expandAroundCenter(i, i + 1); // Even length palindrome
            }

            return s.substr(start, maxLen);
        }
};