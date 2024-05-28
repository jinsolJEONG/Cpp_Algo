#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[15001];
int cnt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //r

    //i
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    //s
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++){
            if(arr[i] + arr[j] == k){
                cnt++;
            }
        }
    //o
    cout << cnt << "\n";

    return 0;
        
}