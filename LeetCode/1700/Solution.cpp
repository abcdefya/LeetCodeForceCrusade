class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for (int s : students) q.push(s);

        int top = 0;
        int skip = 0;

        while (!q.empty() && skip < (int)q.size()) {
            if (q.front() == sandwiches[top]) {
                q.pop();
                top++;
                skip = 0;
            } else {
                int x = q.front();
                q.pop();
                q.push(x);
                skip++;
            }
        }
        return q.size();
    }
};
