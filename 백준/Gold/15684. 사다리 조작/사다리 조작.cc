#include <bits/stdc++.h>
using namespace std;

int n, m, h, a, b;
int used[34][34];
const int INF = 1e9;
int ret = INF;

bool check(){
    for(int i = 1; i <= n; i++){
        int start = i;
        for(int j = 1; j <= h; j++){
            if(used[j][start])start++;
            else if(used[j][start-1])start--;
        }if(start != i) return false;
    }return true;
}

void gogo(int here, int cnt){
    if(cnt > 3 || cnt >= ret)return;
    if(check()){
        ret = min(ret, cnt);
        return;
    }
    for(int i = here; i <= h; i++){
        for(int j = 1; j < n; j++){
            if(used[i][j] || used[i][j-1] || used[i][j+1])continue;
            used[i][j] = 1;
            gogo(i, cnt + 1);
            used[i][j] = 0;
        }
    }
}

int main(){
    //r
    //i
    cin >> n >> m >> h;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        used[a][b] = 1;
    }
    //s
    gogo(1, 0);
    //o
    cout << ((ret == INF) ? -1 : ret) << '\n';
    return 0;
}