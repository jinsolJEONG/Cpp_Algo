#include <bits/stdc++.h>
using namespace std;

int n;
int k;
string s;
map<string, int> mpS;
map<int, string> mpI;
string arr[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //r

    //i
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> s; arr[i] = s;
        mpS[s] = i;
        mpI[i] = s; 
    }
    //s
    for(int i = 0; i < k; i++){
        cin >> s;
        if(atoi(s.c_str())==0)cout << mpS[s] << "\n";
        else cout << arr[atoi(s.c_str())] << "\n";
    }
    //o

    return 0;
}
