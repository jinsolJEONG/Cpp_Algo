#include<bits/stdc++.h>
using namespace std; 

int n, m, mx, used[54][54]; 
char a[54][54];
const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1}; 

void bfs(int y, int x){
    memset(used, 0, sizeof(used)); 
    used[y][x] = 1; 
    queue<pair<int, int>> q; 
    q.push({y, x}); 
    while(q.size()){
        tie(y, x) = q.front(); q.pop(); 
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i]; 
            int nx = x + dx[i]; 
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || used[ny][nx]) continue; 
            if(a[ny][nx] == 'W')continue;
            used[ny][nx] = used[y][x] + 1; 
            q.push({ny, nx});
            mx = max(mx, used[ny][nx]);
        }
    }
    return;
}
int main(){
    //i
    cin >> n >> m; 
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j]; 
    //s
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] == 'L') bfs(i, j); 
    //o
    cout << mx - 1 << "\n";
}