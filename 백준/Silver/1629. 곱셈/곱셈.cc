#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 ll a, b, c;
 ll rst;

ll gogo(ll a, ll b){
    if(b==1)return a % c;
    ll ret = gogo(a, b/2);
    ret = (ret * ret) % c;
    if(b % 2)ret = (ret * a) % c;
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //r

    //i
    cin >> a >> b >> c;
    //s
    rst = gogo(a, b);
    //o
    cout << rst << "\n";
    return 0;
        
}