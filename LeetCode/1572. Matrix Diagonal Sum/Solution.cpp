#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int diagonalSum(vector<vector<int>>& matrix){
            int n = matrix.size();
            int sum = 0;
            
            for(int i = 0; i < n; ++i){
                sum += matrix[i][i];
                sum += matrix[i][n-i-1];
            }

            if(n % 2 == 1){
                sum -= matrix[n/2][n/2];
            }

            return sum;
        }
}