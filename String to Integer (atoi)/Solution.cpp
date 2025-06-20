#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int myAtoi(string s) {
            int i = 0, n = s.length();

            // Skip spaces
            while(i < n; s[i] == ' ') i++;

            // handling sign
            int sign = 1;
            if(i < n && s[i] == '-'){
                sign = -1;
                i++;
            } else if(i < n && s[i] == '+'){
                i++;
            }

            long long res = 0;
            while(i < n){
                int num == s[i] - '0';
                if(num < 0 || num > 9) break;

                if(res > INT_MAX / 10 || (res == INT_MAX / 10 && num > 7)) {
                    return (sign == 1) ? INT_MAX : INT_MIN;
                }
                
                res = res * 10 + num;
                i++;
            }

        }
};