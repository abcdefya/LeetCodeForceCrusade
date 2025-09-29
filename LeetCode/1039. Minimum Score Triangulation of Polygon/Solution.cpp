class Solution {
    public:
        int minScoreTriangulation(vector<int>& values) {
            int n = values.size();
            
            // DP table to store the minimum score for triangulating polygon from i to j
            vector<vector<int>> dp(n, vector<int>(n, 0));
            
            // Calculate DP for all subproblems
            for (int length = 2; length < n; ++length) {  // length is the distance between i and j
                for (int i = 0; i + length < n; ++i) {  // i is the start point of the subproblem
                    int j = i + length;  // j is the end point of the subproblem
                    dp[i][j] = INT_MAX;
                    // Try every possible point k to divide the polygon into two parts
                    for (int k = i + 1; k < j; ++k) {
                        // Formula to find minimum triangulation score
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[k] * values[j]);
                    }
                }
            }
            
            // The answer is the triangulation score for the entire polygon
            return dp[0][n-1];
        }
    };
    