#include <bits/stdc++.h>
using namespace std; 

class Solution {
    public:
        string reverseStr(string s, int k) {
            int n = s.length();
            for(int i = 0; i < n; i += 2 * k) {
                int L = i;
                int R = min(i + k - 1, n - 1);
                while(L < R) {
                    swap(s[L++], s[R--]);
                }
            }
            return s;
        }
};