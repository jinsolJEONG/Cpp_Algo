#include <bits/stdc++.h>
using namespace std;
 
vector<int> v[10001];
int arr[10001], used[10001];
int n, m, a, b;
int mx;
 
int dfs(int here) {  
	used[here] = 1;
	int ret = 1; 
	for(int there : v[here]){
		if(used[there]) continue;
		ret += dfs(there); 
	} 
	return ret;
}
 
int main() { 
    //r

    //i
	cin >> n >> m;  
	while (m--) {
     	cin >> a >> b;  
	    v[b].push_back(a);
	} 
    //s
	for (int i = 1; i <= n; i++) {
		memset(used, 0, sizeof(used));
		arr[i] = dfs(i); 
		mx = max(arr[i], mx);
	} 
    //o
	for (int i = 1; i <= n; i++) 
        if (mx == arr[i]) 
            cout << i << " "; 
	return 0;
}