#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    //i
    cin >> n;
    //s
    int i = 666;
    for(;;i++){
        if(to_string(i).find("666") != string::npos)n--;
        if(n==0)break;
    }
    //o
    cout << i << '\n';
    return 0;
}