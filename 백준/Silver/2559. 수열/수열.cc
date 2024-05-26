#include <bits/stdc++.h>
using namespace std;

int n, cmp;
int psum[100001];
int maxi = -100000;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //r

    //i
    cin >> n >> cmp;
    for(int i = 1; i <= n; i++){
        int tpr = 0;
        cin >> tpr; psum[i] = psum[i-1] + tpr;
    }
    //s
    for(int i = cmp; i <= n; i++){
        maxi = max(maxi, psum[i]-psum[i-cmp]);
    }
    //o
    cout << maxi << '\n';

    return 0;
}