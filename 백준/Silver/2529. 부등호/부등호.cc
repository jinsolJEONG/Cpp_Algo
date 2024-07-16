#include <bits/stdc++.h>
using namespace std;

int k;
int used[10];
char a[10];
vector<string> ret;

bool check(char x, char y, char op){
    if(x < y && op == '<') return true;
    if(x > y && op == '>') return true;
    return false;
}

void go(int idx, string num){
    if(idx == k+1){
        ret.push_back(num);
        return;
    }
    for(int i = 0; i <=9; i++){
        if(used[i]==1)continue;
        if(idx == 0 || check(num[idx-1], i + '0', a[idx -1])){
            used[i] = 1;
            go(idx + 1, num + to_string(i));
            used[i] = 0;
        }
    }return;
}

int main(){
    //r
    //i
    cin >> k;
    for(int i = 0; i < k; i++)
        cin >> a[i];
    //s
    go(0, "");
    sort(ret.begin(), ret.end());
    //o
    cout << ret[ret.size()-1] << '\n' << ret[0] << '\n';
    return 0;
}