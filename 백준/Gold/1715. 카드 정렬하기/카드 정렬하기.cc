#include<iostream>
#include<queue>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//rst
	int N;
	int sum = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	//input
	cin >> N;
	for (int i = 0; i < N; i++) {
		int data;
		cin >> data;
		pq.push(data);
	}
	//solve
	while (pq.size() != 1) {
		int first = pq.top();
		pq.pop();
		int cnt = first + pq.top();
		pq.pop();
		sum += cnt;
		pq.push(cnt);
	}
	//output
	cout << sum << "\n";
	return 0;
}