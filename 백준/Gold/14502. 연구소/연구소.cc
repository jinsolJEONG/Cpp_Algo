#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[10][10], used[10][10];
vector<pair<int,int>> vrs, wall;
int ret;
int dy[]={-1,0,1,0}, dx[]={0,1,0,-1};

void dfs(int y, int x){
    for(int i =0 ; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || nx<0 || ny>=n || nx >= m || used[ny][nx]==1 || a[ny][nx]==1 )
            continue;
        used[ny][nx]=1;
        dfs(ny, nx);
    }return;
}

int solve(){
    //r
    fill(&used[0][0], &used[0][0]+10*10, 0);
    //s
    //바이러스 기준으로 dfs 돌려서 바이러스 퍼트리기
    for(pair<int, int>b : vrs){
        used[b.first][b.second] = 1;
        dfs(b.first, b.second);
    }
    //0카운트해서 리턴 
    int cnt = 0;
    for(int i = 0; i<n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j]==0 && !used[i][j])cnt++;
    return cnt;
}

int main(){
    //r
    //i
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j]==2) vrs.push_back({i, j});
            if(a[i][j]==0) wall.push_back({i, j});
        }
    //s
    //미리 벽 64C3 세워두고 가장 큰 값 구하기
    for(int k = 0; k < wall.size(); k++)
        for(int i = 0; i < k; i ++)
            for(int j = 0; j < i; j++){
                a[wall[k].first][wall[k].second] = 1;
                a[wall[i].first][wall[i].second] = 1;
                a[wall[j].first][wall[j].second] = 1;
                ret = max(ret, solve());
                a[wall[k].first][wall[k].second] = 0;
                a[wall[i].first][wall[i].second] = 0;
                a[wall[j].first][wall[j].second] = 0;
            }
    //o
    cout << ret << '\n';
    return 0;
}