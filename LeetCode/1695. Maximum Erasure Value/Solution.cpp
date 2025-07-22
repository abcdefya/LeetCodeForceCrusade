#include <bits/stdc++.h>
using namespace std;

class Solution {
    string makeFancyString(string s) {
        int n = s.length();
        if (n <= 2) {return s};

        int write = 2;

        for(int read = 2; read < n; ++read) {
            if(s[read] == s[write - 1] && s[read] == s[write - 2]) {
                continue;
            }
            s[write] = s[read];
            write++;
        }

        s.resize(write);
        return s;
    }
}