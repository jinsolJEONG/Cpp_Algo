#include <bits/stdc++.h>
using namespace std;

int n;
string refer;
string s;
string cStart, cEnd;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //r

    //i
    cin >> n;
    cin >> refer;
    int point;
    point = refer.find('*');
    cStart = refer.substr(0, point); 
    cEnd = refer.substr(point+1);
    //s
    for(int i = 0; i < n; i++){
        cin >> s;
        //1. refer보다 짧은 경우
        if(cStart.size() + cEnd.size() > s.size()) cout << "NE\n";
        //2. 짧지 않은데
        else {
            //해당하는 경우
            if(cStart == s.substr(0, cStart.size()) && cEnd == s.substr(s.size()-cEnd.size()))cout << "DA"<<"\n";
            //일치하지 않는 경우
            else cout << "NE"<<'\n';
        }
    }
    //o

    return 0;
}