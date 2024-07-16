#include <bits/stdc++.h>
using namespace std;

int r, c, ret;
char a[30][30], used[30];
int dy[]={-1, 0, 1, 0}, dx[]={0,1,0,-1};

void dfs(int y, int x, int cnt){
    ret = max(ret, cnt);
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i]; int nx = x + dx[i];
        if(ny<0 || nx<0 || ny >= r || nx >= c)continue;

        int next = (int)a[ny][nx] -'A';
        if(used[next]==0){
            used[next]=1;
            dfs(ny, nx, cnt+1);
            used[next]=0;
        }
    }
    return;
}

int main(){
    //r
    //i
    cin >> r >> c;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> a[i][j];
    //s
    used[(int)a[0][0]-'A'] = 1;
    dfs(0,0,1);
    //o
    cout << ret << '\n';
    return 0;
}