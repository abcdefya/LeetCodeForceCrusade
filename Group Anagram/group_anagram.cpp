#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ana;

        for(string& s: strs) {
            string key = s;
            sort(key.begin(), key.end());
            ana[key].push_back(s);
        }


        vector<vector<string>> result;
        for(auto& p: ana){
            result.push_back(p.second);
        }
    }
}