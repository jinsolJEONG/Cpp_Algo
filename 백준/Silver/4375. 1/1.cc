#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;

int main(){
    //r

    //i
    while(scanf("%d", &n) != EOF){
        int cnt = 1; int digit = 1;
        while(1){
            if(cnt % n == 0){
                printf("%d\n", digit);
                break;
            }else{
                cnt = (cnt * 10) + 1;
                cnt %= n;
                digit++;
            }
        }
    }

    //s

    //o


    return 0;
}