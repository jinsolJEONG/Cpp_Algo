#include <bits/stdc++.h> 
using namespace std; 
#define MAX_N 16

const int INF = 1e9;
int n, dp[MAX_N][1 << MAX_N], dist[MAX_N][MAX_N];

int tsp(int here, int used){
    if(used == (1 << n) - 1){
        return dist[here][0] ? dist[here][0] : INF;
    }
    int &ret = dp[here][used];
    if(ret != -1) return ret;
    ret = INF;
    for(int i = 0; i < n; i++){
        if(used & (1 << i)) continue;
        if(dist[here][i] == 0) continue;
        ret = min(ret, tsp(i, used | (1 << i)) + dist[here][i]);
    }
    return ret;
}

int main() {
    //i
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> dist[i][j];
    //s
    memset(dp, -1, sizeof(dp));
    //o
    cout << tsp(0, 1) << '\n';
    return 0;
}
