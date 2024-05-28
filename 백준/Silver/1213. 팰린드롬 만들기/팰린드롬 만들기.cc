#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[200];
char mid;
int flag;
string rst;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //r

    //i
    cin >> s;
    for(int c : s)cnt[c]++;
    //s
    for(int i = 'Z'; i >= 'A'; i--){
        if(cnt[i]){
            //홀수개인 경우
            if(cnt[i] & 1){
                mid = char(i); 
                flag++;
                cnt[i]--;
            }
            //만약 홀수개가 두개이면 성립안되니까
            if(flag == 2)break;
            //짝수개인 것들은 앞뒤로 붙이기
            for(int j = 0; j < cnt[i]; j += 2){
                rst = char(i) + rst; //앞
                rst += char(i); //뒤
            }            
        }
    }
    //홀수 가운데 끼워넣기
    if(mid)rst.insert(rst.begin() + rst.size()/2, mid);
    //o
    if(flag == 2)cout << "I'm Sorry Hansoo\n";
    else cout << rst << "\n";

    return 0;
}
