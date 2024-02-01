#include <iostream>

using namespace std;

int N;
bool isPrime(int num){
    for(int i = 2; i <= num/2; i++){
        if(num%i == 0)return false;
    }
    return true;
};

void dfs(int number, int jari){
    if(jari == N){
        if(isPrime(number))cout << number<< endl;
        return;
    }
    //뒷자리
    for(int i = 1; i <= 9; i++){
        if(i%2==0)continue;
        if(isPrime(number*10+i)){
            dfs(number*10+i, jari+1);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //rst
    //input
    cin >> N;
    //solve
    dfs(2,1);
    dfs(3,1);
    dfs(5,1);
    dfs(7,1);
    //output
}