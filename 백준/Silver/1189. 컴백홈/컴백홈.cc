#include <bits/stdc++.h>
using namespace std;

int n, m, k;
string s;
char a[10][10];
int dy[] = {-1,0,1,0}, dx[]={0,1,0,-1};
int used[10][10];

int go(int y, int x){
    if(y==0 && x==m-1){
        if(k == used[y][x])return 1;
        return 0;
    }
    int ret = 0;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i]; int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || used[ny][nx] || a[ny][nx]=='T')continue;
        used[ny][nx]= used[y][x] +1;
        ret += go(ny, nx);
        used[ny][nx] = 0;
    }return ret;
}

int main(){
    //r
    //i
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++){
        cin >> s;
        for (int j = 0; j < m; j++){
            a[i][j] = s[j];
        }
    }
    //s
    used[n-1][0]=1;
    //o
    cout << go(n-1,0) << '\n';
    return 0;
}