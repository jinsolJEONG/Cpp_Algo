#include <bits/stdc++.h>
using namespace std;

int t;
string s;

bool check(string s){
    stack<char> stk;
    for(char c : s){
        if(c == '(')stk.push(c);
        else{
            if(!stk.empty())stk.pop();
            else return false;
        }
    }return stk.empty();
}


int main(){
    //r
    //i
    cin >> t;
    //s
    for(int i = 0; i < t; i ++){
        cin >> s;
        if(check(s)) cout << "YES\n";
        else cout << "NO\n";
    }
    //o
    return 0;
}