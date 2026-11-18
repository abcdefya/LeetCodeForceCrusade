class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indeg(numCourses, 0);

        for (auto& p : prerequisites) {
            int a = p[0], b = p[1];
            graph[b].push_back(a);
            indeg[a]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) q.push(i);
        }

        vector<int> order;
        order.reserve(numCourses);

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            order.push_back(course);
            for (int next : graph[course]) {
                if (--indeg[next] == 0)
                    q.push(next);
            }
        }

        if ((int)order.size() == numCourses) return order;
        return {};
    }
};
