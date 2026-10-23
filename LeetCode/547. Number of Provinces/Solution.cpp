// DFS
class Solution {
public:
    void dfs(int cur, vector<vector<int>>& isConnected, vector<bool>& isVisited) {
        isVisited[cur] = true;
        int n = isConnected.size();
        for (int i = 0; i < n; i++)
            if (isConnected[cur][i] == 1 && !isVisited[i])
                dfs(i, isConnected, isVisited);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> isVisited(n, false);
        int count = 0;
        for (int c = 0; c < n; c++) {
            if (!isVisited[c]) {
                count++;
                dfs(c, isConnected, isVisited);
            }
        }
        return count;
    }
};

// BFS
// class Solution {
// public:
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size();
//         vector<bool> isVisited(n, false);
//         int count = 0;

//         for (int c = 0; c < n; c++) {
//             if (isVisited[c]) continue;
//             count++;
//             isVisited[c] = true;
//             queue<int> q;
//             q.push(c);

//             while (!q.empty()) {
//                 int cur = q.front();
//                 q.pop();

//                 for (int i = 0; i < n; i++) {
//                     if (isConnected[cur][i] == 1 && !isVisited[i]) {
//                         isVisited[i] = true;
//                         q.push(i);
//                     }
//                 }
//             }
//         }
//         return count;
//     }
// };