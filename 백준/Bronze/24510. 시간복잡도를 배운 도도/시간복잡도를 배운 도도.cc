#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

	int mx = 0;
	int N; 
    cin >> N;
	while (N--) {
		string s; 
        cin >> s;
		int cnt = 0;
		int slen = s.length();
		slen -= 2;
		for (int i = 0; i < slen; i++) 
            if (s.substr(i, 3) == "for") 
                cnt++;
		slen -= 2;
		for (int i = 0; i < slen; i++) 
            if (s.substr(i, 5) == "while")
                cnt++;
		mx = max(mx, cnt);
	}
	cout << mx;
}