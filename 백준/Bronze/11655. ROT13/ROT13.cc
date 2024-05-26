#include <bits/stdc++.h>
using namespace std;

string s;
char c;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //r

    //i
    getline(cin, s);
    //s
    for(int i = 0; i < s.size(); i++){
        if('A'<=s[i] && 'Z'>=s[i]){
            if(s[i] + 13 > 'Z'){
                c = s[i] +13 -26;
                cout << c;
            }
            else {
                c = s[i] + 13;
                cout << c;
            }
        }
        else if('a'<=s[i] && 'z'>=s[i]){
            if(s[i] + 13 > 'z'){
                c = s[i] +13 -26;
                cout << c;
            }
            else {
                c = s[i] + 13;
                cout << c;
            }
        }
        else cout << s[i];
    }cout << "\n";
    //o

    return 0;
}