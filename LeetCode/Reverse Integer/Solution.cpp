#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0; // Trường hợp đặc biệt: x = 0
        
        int res = 0; // Kết quả đảo ngược
        
        while (x != 0) {
            int extractNum = x % 10;
            
            // Kiểm tra tràn số
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && extractNum > INT_MAX % 10)) {
                return 0;
            }
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && extractNum < INT_MIN % 10)) {
                return 0;
            }
            
            res = res * 10 + extractNum;
            x = x / 10;
  
        }
        
        return res;
    }
};

