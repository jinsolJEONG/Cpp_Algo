#include <bits/stdc++.h>
using namespace std;

int n, m, a[54][54];
int rst = 9999999;
vector<pair<int, int>> home, chic;
vector<vector<int>> chicList;
vector<int> v;

void combi(int start, vector<int> v){
    if(v.size()==m){
        chicList.push_back(v);
        return;
    }
    for(int i = start + 1; i < chic.size(); i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }return;
}

int main(){
    //r
    //i
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j]==1)home.push_back({i, j});
            if(a[i][j]==2)chic.push_back({i,j});
        }
    //s
    combi(-1,v);
    for(vector<int> cList : chicList){
        int ret = 0;
        for(pair<int, int> house : home){
            int mn = 99999999;
            for(int ch : cList){
                int tmp = abs(house.first - chic[ch].first) + 
                    abs(house.second - chic[ch].second);
                mn = min(mn, tmp);
            }
            ret += mn;
        }
        rst = min(rst, ret);
    }
    //o
    cout << rst << '\n';

    return 0;
}