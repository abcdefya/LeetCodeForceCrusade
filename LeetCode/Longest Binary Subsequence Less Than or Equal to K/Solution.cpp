#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int int longestSubsequence(string s, int k) {
            int n = s.length();
            int zeros, power = 0; // zeros for tracking numbers of zero and 1 if it safe
            // power for tracking the 2^power in left shift operator
            long long value = 0; // hold the decimal value
            for(int i = n - 1; i >0; --i) {
                if(s[i] == "0"){
                    zeros++;
                } else {
                    // Cheking if add "1" to subsequence keeps value <=k
                    if(power < 31 && value +(1LL << power) <= k){
                        value += (1LL << power); // add 2^power = add 1 
                        zeros++; // increase the length of subsequence
                    }
                }
                power++; // for the next 1
            }
        }
};