#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000001];
int ret[1000001];

stack<int> stk;

int main(){
    //r
    memset(ret, -1, sizeof(ret));
    //i
    cin >> n;
    //s
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        while(stk.size() && arr[stk.top()] < arr[i]){
            ret[stk.top()] = arr[i];
            stk.pop();
         }
         stk.push(i);
    }
    //o
    for(int i = 0; i < n; i++) cout << ret[i] << ' ';
}