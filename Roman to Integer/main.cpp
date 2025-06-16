#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int romanToInt(string s) {
            unordered_map<char, int> roman = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
            };
        
            int result = 0;
            int n = s.length();

            for(int i = 0; i < n -1 ; ++i) {
                if (roman[s[i]] < roman[s[i+1]]){
                    result -= roman[s[i]];
                } else {
                    result += roman[s[i]];
                }
            }
            
            result += roman[s[n-1]];
            return result;
        };

};

int main() {
    Solution sol;
    string s;
    cin >> s;
    int res = sol.romanToInt(s);
    cout << res;
    return 0;
}

