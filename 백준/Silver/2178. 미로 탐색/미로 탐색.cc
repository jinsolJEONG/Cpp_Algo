#include<bits/stdc++.h>
using namespace std; 
const int max_n = 104; 
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1}; 
int n, m, a[max_n][max_n], used[max_n][max_n], y, x; 
int main(){ 
    scanf("%d %d", &n, &m); 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &a[i][j]);
        }
    } 
    queue<pair<int, int>> q;  
    used[0][0] = 1;
    q.push({0, 0});  
    while(q.size()){
        tie(y, x) = q.front(); q.pop(); 
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i]; 
            int nx = x + dx[i]; 
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0 || used[ny][nx] == 1 ) continue; 
            used[ny][nx] = used[y][x] + 1; 
            q.push({ny, nx}); 
        } 
    }
    printf("%d", used[n - 1][m - 1]); 
    return 0;
}  
