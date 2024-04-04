#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//rst
	int N;
	int cnt = 0;
	int endpoint = -1;
	//input
	cin >> N;
	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].second; //start
		cin >> v[i].first; //end
	}
	//solve
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		if (v[i].second >= endpoint) {
			endpoint = v[i].first;
			cnt++;
		}
	}
	//output
	cout << cnt << '\n';
	return 0;
}