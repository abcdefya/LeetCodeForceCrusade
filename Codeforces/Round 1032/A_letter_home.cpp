#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n, s;
        cin >> n >> s; 
        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }

        int min_x = x[0];
        int max_x = x[n-1];

        int steps = min(abs(s-min_x) + (max_x - min_x), abs(s - max_x) + (max_x -min_x));
        cout << steps << "\n";
        return 0;
    }
}