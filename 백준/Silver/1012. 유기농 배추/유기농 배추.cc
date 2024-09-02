#include <bits/stdc++.h>
using namespace std;

int t,n,m,k,x,y;
int dy[]={-1,0,1,0}, dx[]={0,1,0,-1};
int a[54][54], used[54][54];

void dfs(int y, int x){
    used[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0||nx<0||ny>=n||nx>=m)continue;
        if(a[ny][nx] ==1 && used[ny][nx]!=1)
            dfs(ny, nx);
    }
    return;
}


int main(){
    //r
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //i
    cin >> t;
    while(t--){
        int ret = 0;
        fill(&a[0][0], &a[0][0]+54*54, 0);
        fill(&used[0][0], &used[0][0]+54*54, 0);
        cin >> m >> n >> k;
        for(int i =0; i < k; i++){
            cin >> x >> y;
            a[y][x] = 1;
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(a[i][j]==1 && used[i][j]==0){
                    dfs(i,j);
                    ret++;
                }
            }
        cout << ret << '\n';
    }
    //s
    //o
    
    return 0;
}