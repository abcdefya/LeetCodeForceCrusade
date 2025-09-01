#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int n = (int)matrix.size();

            // Step 1: Transpose the matrix
            for(int i = 0; i < n; ++i) {
                for(int j = i + 1; j < n; ++j) {
                    std::swap(matrix[i][j], matrix[j][i]);
                }
            }

            // Step 2: Reverse each row
            for (int i = 0; i < n; ++i) {
                std::reverse(matrix[i].begin(), matrix[i].end());
            }
        }
}