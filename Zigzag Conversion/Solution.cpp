#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string convert(string s, int numRows) {
            if (numRows == 1 || numRows >= s.length()) return s; // Edge cases
            int n = s.length();
            string zigzazStr = "";

            int cycleLen = 2*(numRows - 1);

            for (int i = 0; i < numRows; ++i) {
                for(int k = 0; i + k * cycleLen; ++k) {
                    zigzazStr += s[i + k * cycleLen];

                    if(i != 0 && i != numRows - 1) {
                        int upwardIdx = (k + 1)*cycleLen - i;
                        if(upwardIdx < n) {
                            zigzazStr += s[upwardIdx];
                        }
                    }
                }

            }
            
            return zigzazStr;
        }
};

