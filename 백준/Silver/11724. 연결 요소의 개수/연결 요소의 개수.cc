#include <iostream>
#include <vector>

using namespace std;

vector<vector <int>> A;
char used[1000];

void dfs(int lev){
    if(used[lev]==1)return;
    used[lev] = 1;
    for(int i : A[lev]){
        if(used[i]==0)dfs(i);
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //rst

    int N, M;
    int ans = 0;
    //input
    cin >> N >> M;
    A.resize(N+1);//배열크기 재지정?
    for(int i = 0; i < M; i++){
        int s, e;
        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    }
    //sol
    for(int i = 1; i <= N; i ++){
        if(used[i]==0){
            ans++;
            dfs(i);
        }
    }
    //output
    cout << ans << endl;
}