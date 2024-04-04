#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//rst
	int N;
	int num_1 = 0;
	int num_0 = 0;
	int result = 0;
	priority_queue<int> pq_p;
	priority_queue<int, vector<int>, greater<int>> pq_n;

	//input
	cin >> N;
	for (int i = 0; i < N; i++) {
		int data;
		cin >> data;
		if (data == 0) num_0++;
		else if (data == 1)num_1++;
		else if (data > 1)pq_p.push(data);
		else pq_n.push(data);
	}

	//solve1 positive
	while (pq_p.size() > 1) {
		int fst = pq_p.top();
		pq_p.pop();
		result += fst * pq_p.top();
		pq_p.pop();
	}if (pq_p.size() == 1) {
		result += pq_p.top();
		pq_p.pop();
	}
	//solve2 positive
	while (pq_n.size() > 1) {
		int fst = pq_n.top();
		pq_n.pop();
		result += fst * pq_n.top();
		pq_n.pop();
	}if (pq_n.size() == 1) {
		if (num_0 > 0)pq_n.pop();
		else {
			result += pq_n.top();
			pq_n.pop();
		}
	}
	//solve3 1
	result += num_1;
	//output
	cout << result << '\n';

	return 0;
}