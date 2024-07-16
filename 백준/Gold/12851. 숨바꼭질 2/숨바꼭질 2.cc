#include <bits/stdc++.h>
using namespace std;
//bfs로 풀어야하는데..
int n, k;
const int mx = 100000;
int times[mx+4];
int ways[mx+4];

void bfs(){
    times[n] = 1;
    ways[n] = 1;
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int next : {now-1, now+1, now*2}){
            if(next >= 0 && next <= mx){
                if(!times[next]){
                    times[next] = times[now] + 1;
                    ways[next] = ways[now];
                    q.push(next);
                }else if(times[next]==times[now]+1)
                    ways[next] += ways[now];
            }

        }
    }return;

}

int main(){
    //r
    //i
    cin >> n >> k;
    //s
    //반례:처음부터 같은 위치라면?
    if(n==k){
        cout << "0" << '\n' << "1" << '\n';
        return 0;
    }
    bfs();
    //o
    cout << times[k]-1 << '\n' << ways[k];
    return 0;
}
