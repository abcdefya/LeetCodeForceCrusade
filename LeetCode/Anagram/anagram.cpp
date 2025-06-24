#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool isAnagram(string s, string t) {
        // If the two lengths don't match together --> false
        if(s.length() != t.length()) return false;

        unordered_map<char, int> freq;
        for(char c: s) {
            freq[c]++;
        }

        for(char c: t) {
            if(!freq.count(c) || freq[c] == 0) return false;
            freq[c]--;
        }

        for(const auto& p : freq) {
            if(p.second != 0) return false;
        }

        return true;

    }
}