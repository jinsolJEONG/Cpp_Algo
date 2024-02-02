#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> A;
char used[2000];
bool arrive;

void dfs(int now, int lev){
    if(lev == 5 || arrive){
        arrive = true;
        return;
    }

    used[now] = 1;
    for(int i : A[now]){
        if(used[i]==0){
            dfs(i, lev+1);
        }
    }
    used[now] = 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //reset
    int N, M;
    arrive = false;
    //input
    cin >> N >> M;
    A.resize(N);
    for(int i = 0; i < M; i++){
        int v, e;
        cin >> v >> e;
        A[v].push_back(e);
        A[e].push_back(v);
    }
    //solve
    for(int i = 0; i < N; i++){
        dfs(i, 1);
        if(arrive)break;
    }
    //output
    if(arrive)cout << 1 << endl;
    else cout << 0 << endl;
}