#include <bits/stdc++.h>
using namespace std;

class Solution {
    public: 
        vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        //int num_group = n / k;
        vector<string> res;
        int remainder = n % k;

        if(remainder > 0){
            std::string append_str(k - remainder, fill);
            s += append_str;
        }

        for(int i = 0; i < s.length(); i += k){
            string sub_str = s.substr(i, k);
            res.push_back(sub_str);
        }
        return res;
    }
};
