#include <bits/stdc++.h>
using namespace std;

int n,m,y,x;
int box[1004][1004], dist[1004][1004];
int dy[]={-1,0,1,0}, dx[]={0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //r
    queue<pair<int, int>> q;
    //i
    cin >> m >> n;
    for(int i = 0 ; i < n; i++)
        for(int j =0 ; j < m; j++){
            cin >> box[i][j];
            if(box[i][j]==1) q.push({i,j});
            else if(box[i][j]==0)dist[i][j]=-1;
        }
    //s
    while(q.size()){
        tie(y,x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0||nx<0||ny>=n||nx>=m)continue;
            if(box[ny][nx]!=0 || dist[ny][nx]!=-1)continue;
            dist[ny][nx] = dist[y][x]+1;
            q.push({ny, nx});
        }
    }
    //o
    int rst = -1e9;
    for(int i = 0; i< n; i++)
        for(int j = 0; j < m; j++){
            if(dist[i][j]==-1){
                cout << -1;
                return 0;
            }
            rst = max(rst, dist[i][j]);
        }
    cout << rst << '\n';
    return 0;
}