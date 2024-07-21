#include <bits/stdc++.h>
using namespace std;

int a[504][504], used[504][504];
int n, m, ret;
int dy[]={-1,0,1,0}, dx[]={0,1,0,-1};

// 'ㅗ' 
void fuxxCheck(int x, int y) {
    int shapes[4][3][2] = {
        {{0, 1}, {0, -1}, {-1, 0}}, // ㅗ
        {{0, 1}, {0, -1}, {1, 0}},  // ㅜ
        {{1, 0}, {-1, 0}, {0, 1}},  // ㅏ
        {{1, 0}, {-1, 0}, {0, -1}}  // ㅓ
    };

    for (int shape = 0; shape < 4; shape++) {
        int sum = a[x][y];
        bool valid = true;
        for (int i = 0; i < 3; i++) {
            int nx = x + shapes[shape][i][0];
            int ny = y + shapes[shape][i][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                valid = false;
                break;
            }
            sum += a[nx][ny];
        }
        if (valid) {
            ret = max(ret, sum);
        }
    }
}

void tetris(int lev, int x, int y, int sum) {
    if (lev == 3) {
        ret = max(ret, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || used[nx][ny]) continue;
        used[nx][ny] = 1;
        tetris(lev + 1, nx, ny, sum + a[nx][ny]);
        used[nx][ny] = 0;
    }
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fuxxCheck(i, j);
			used[i][j] = 1;
			tetris(0, i, j, a[i][j]);
			used[i][j] = 0;
		}
	}
 
	cout << ret;
}