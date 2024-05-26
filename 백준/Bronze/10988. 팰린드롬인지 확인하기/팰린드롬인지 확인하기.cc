#include <bits/stdc++.h>
using namespace std;

string s;
string temp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //r

    //i
    cin >> s;
    //s
    temp = s;
    reverse(temp.begin(), temp.end());
    //o
    if(temp == s)cout << 1 << "\n";
    else cout << 0 << "\n";

    return 0;
}