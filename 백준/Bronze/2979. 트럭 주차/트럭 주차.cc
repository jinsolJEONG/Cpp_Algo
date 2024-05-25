#include <bits/stdc++.h>
using namespace std;

int arr[101];
int sum;
int pay[4];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //r

    //i
    for(int i = 1; i <= 3; i++)cin >> pay[i];
    //s
    for (int i = 0; i < 3; i++){
        int carIn =0, carOut =0;
        cin >> carIn >> carOut;
        for(int j = carIn; j <carOut; j++)arr[j]++;
    }
    for(int i = 0; i < 101; i++){
        if(arr[i]==1)arr[i] *= pay[1];
        else if(arr[i]==2)arr[i] *= pay[2];
        else if(arr[i]==3)arr[i] *= pay[3];
    }
    for(int i = 0; i < 101; i++)sum += arr[i];
    //o
    cout << sum << "\n";

    return 0;
}