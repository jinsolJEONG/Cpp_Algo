#include <bits/stdc++.h>
using namespace std;

int member;
string s;
char c;
int alpha[26];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //r

    //i
    cin >> member;
    for(int i = 0; i < member; i++){
        //s.erase(0, s.size());
        cin >> s;
        alpha[s[0]-'a']++;
    }
    //s
    int cnt = 0;
    //o
    for(int i = 0; i < 26; i++){
        if(alpha[i] >= 5){
            c = i + 'a';
            cout << c;
            cnt++;
        }
    }
    if(cnt == 0)cout << "PREDAJA";

    return 0;
}