#include <bits/stdc++.h>
using namespace std;

int n;
int ret = 1;
int arr[101][101], used[101][101];
int dy[]={-1,0,1,0}, dx[]={0,1,0,-1};

void dfs(int y, int x, int lev){
    used[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0||nx<0||ny>=n||nx>=n)continue;
        if(used[ny][nx]==0 && arr[ny][nx] > lev)
            dfs(ny, nx, lev);
    }return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //i
    cin >> n;
    for(int i =0; i < n; i++)
        for(int j= 0; j < n; j++){
            cin >> arr[i][j];
        }
    //s
    for(int l = 1; l <= 100; l++){
        fill(&used[0][0], &used[0][0]+101*101, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(used[i][j]==0 && arr[i][j] > l){
                    dfs(i, j, l);
                    cnt++;
                }
        ret = max(ret, cnt);
    }
    //o
    cout << ret << '\n';
    return 0;
}