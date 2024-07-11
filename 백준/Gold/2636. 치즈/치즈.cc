#include <bits/stdc++.h>
using namespace std;

int dy[]={-1,0,1,0}, dx[]={0,1,0,-1};
int n, m;
int a[104][104], used[104][104];
int cnt, cnt2;
vector<pair<int, int>>v;

void dfs(int y, int x){
    used[y][x] = 1;
    if(a[y][x]==1){
        v.push_back({y,x});
        return;
    }
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx<0 || ny>=n || nx>= m || used[ny][nx]==1)
            continue;
        dfs(ny, nx);
    }
    return;
}

int main(){
    //r
    //i
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j =0; j < m; j++)
            cin >> a[i][j];
    //s
    while(1){
        //r
        fill(&used[0][0], &used[0][0]+104*104, 0);
        v.clear();
        //s
        dfs(0,0);
        //모두 녹기 한시간 전 치즈
        cnt2 = v.size();
        //총 걸린 시간
        cnt++;
        //녹은 치즈 지우기
        for(pair<int, int> vec : v)
            a[vec.first][vec.second]=0;
        //치즈가 모두 녹았는지 확인
        bool flag = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(a[i][j]!=0) flag = 1;
        if(!flag)break;
    }
    //o
    cout << cnt << '\n' << cnt2;
    return 0;
}