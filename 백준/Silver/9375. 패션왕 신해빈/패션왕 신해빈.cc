#include <bits/stdc++.h>
using namespace std;

int n, t;
string a, b;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //r

    //i
    cin >> t;
    while(t--){
        map<string, int> mp;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            mp[b]++;
        }
        int rst = 1;
        for(auto i : mp){
            rst *= (i.second +1);
        }
        rst--;

        cout << rst << "\n";
    }
    //s

    //o

    return 0;
}