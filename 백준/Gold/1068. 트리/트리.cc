#include<bits/stdc++.h>
using namespace std;

int n, r;
int tmp, root;
vector<int> adj[54];

int dfs(int here){
    int ret = 0;
    int child = 0;
    for(int there : adj[here]){
        if(there == r) continue;
        ret += dfs(there);
        child++;
    }
    if(child == 0) return 1;
    return ret;
}

int main(){
    //i
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        if(tmp == -1)root = i;
        else adj[tmp].push_back(i);
    }
    cin >> r;
    //s
    //루트노드가 사라진다면
    if(r == root){
        cout << 0 << "\n";
        return 0;
    }
    //s, o
    cout << dfs(root) << "\n";
    return 0;
}
