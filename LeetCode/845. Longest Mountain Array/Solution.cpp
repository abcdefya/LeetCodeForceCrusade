#include <bits/stdc++.h>
using namespace std;

class Solution {
    int longestMountain(vector<int>& arr) {
        int n = (int)arr.size();
        int up = 0, down = 0, ans = 0;
        if (n < 3) return 0;

        for(int i = 1; i < n; ++i) {
            // Reset if plateau, or if we start ascending after already descending
            if ( (down > 0 && arr[i] > arr[i - 1]) || arr[i] == arr[i - 1]) {
                up = down = 0;
            }

            if (arr[i] > arr[i - 1]) {
                up++;
            } else if (arr[i] < arr[i - 1]) {
                down++;
            }

            if (up > 0 && down > 0) {
                ans = max(ans, up + down + 1);
            }

        }
        return ans;
    }
};