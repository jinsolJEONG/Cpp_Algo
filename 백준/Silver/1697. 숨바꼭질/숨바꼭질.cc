#include <bits/stdc++.h>
using namespace std;

const int mx = 100001;

int bfs(int start, int end) {
    vector<bool> used(mx, false);
    queue<pair<int, int>> q;
    
    q.push({start, 0});
    used[start] = true;

    while (!q.empty()) {
        int current = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (current == end) {
            return steps;
        }

        // x - 1
        if (current - 1 >= 0 && !used[current - 1]) {
            used[current - 1] = true;
            q.push({current - 1, steps + 1});
        }
        
        // x + 1
        if (current + 1 <= mx && !used[current + 1]) {
            used[current + 1] = true;
            q.push({current + 1, steps + 1});
        }
        
        // 2 * x
        if (current * 2 <= mx && !used[current * 2]) {
            used[current * 2] = true;
            q.push({current * 2, steps + 1});
        }
    }

    return -1;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    cout << bfs(n, k) << '\n';
    return 0;
}
