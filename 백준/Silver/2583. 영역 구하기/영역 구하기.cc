#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int x_l, y_l, x_r, y_r;
int arr[104][104], used[104][104];
vector<int> ret;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

int dfs(int y, int x){
    used[y][x] = 1;
    int rst = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if( ny<0 || nx<0 || ny>=n || nx>=m || used[ny][nx]!=0 || arr[ny][nx]!=0 )continue;
        rst += dfs(ny, nx);
    }
    return rst;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //r

    //i
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++){
        cin >> x_l >> y_l >> x_r >> y_r;
        for(int x = x_l; x < x_r; x++){
            for(int y = y_l; y < y_r; y++)
                arr[y][x] = 1;
        }
    }
    //s
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(arr[i][j]==0 & used[i][j]==0){
                ret.push_back(dfs(i,j));
            }
        }
    //o
    sort(ret.begin(), ret.end());
    cout << ret.size() << '\n';
    for(int i : ret) cout << i << ' ';
    return 0;
}