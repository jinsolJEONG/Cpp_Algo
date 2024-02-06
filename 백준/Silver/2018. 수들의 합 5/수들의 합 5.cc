#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//rst
	int N;
	int s_idx = 1;
	int e_idx = 1;
	int sum = 1;
	int cnt = 1;
	//input
	cin >> N;
	//solve
	while(e_idx != N){
		if(sum == N){
			cnt++;
			e_idx++;
			sum += e_idx;
		}
		else if(sum > N){
			sum = sum - s_idx;
			s_idx++;
		}
		else{
			e_idx ++;
			sum += e_idx;
		}
	}
	//output
	cout << cnt << endl;
}