#include<iostream>
#include<vector>

using namespace std;


int main() {
	//rst
	int N, K;
	int sum = 0;
	//input
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		int m = 0;
		cin >> A[i];
	}
	//solve
	for (int i = N - 1; i >= 0; i--) {
		if (A[i] <= K) {
			sum += K / A[i];
			K = K % A[i];
		}
	}
	//output
	cout << sum << "\n";

	return 0;
}