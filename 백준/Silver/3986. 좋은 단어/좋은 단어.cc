#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int cnt;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //r

    //i
    cin >> n;

    //s
    for(int i = 0; i < n; i++){
        cin >> s;
        stack<char> stk;
        for(char c : s){
            if(stk.size() > 0 && stk.top() == c)stk.pop();
            else stk.push(c);
        }
        if(stk.size() == 0)cnt++;
    }

    //o
    cout << cnt << "\n";

    return 0;
        
}