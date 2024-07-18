#include <bits/stdc++.h>
using namespace std;
//비트마스킹
const int INF = 987654321;
int n, mp, mf, ms, mv;
int sum;
int b, c, d, e, ret = INF;
struct A{
    int mp, mf, ms, mv, cost;
}a[16];
map<int, vector<vector<int>>> v_map;

int main(){
    //r
    //i
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for(int i = 0; i < n; i++)
        cin >> a[i].mp >> a[i].mf >> a[i].ms >> a[i].mv >> a[i].cost;
    //s
    for(int i = 1; i < (1<<n); i++){
        b=c=d=e=sum = 0;
        vector<int> v;
        for(int j = 0; j < n; j++){
            if(i & 1 << j){
                v.push_back(j+1);
                b += a[j].mp;
                c += a[j].mf;
                d += a[j].ms;
                e += a[j].mv;
                sum += a[j].cost;
            }
        }
        if(b >= mp && c>= mf && d >= ms && e >= mv)
            if(ret >= sum){
                ret = sum;
                v_map[ret].push_back(v);
            }
    }
    //o
    if(ret == INF)cout << -1 << '\n';
    else{
        sort(v_map[ret].begin(), v_map[ret].end());
        cout << ret << '\n';
        for(int o : v_map[ret][0]) cout << o << ' ';
    }
    return 0;
}