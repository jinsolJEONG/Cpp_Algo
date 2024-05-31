#include <iostream>
#include <algorithm>
#include <vector>
#define INF 2000000001
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> vec(n);

	for (int i = 0; i < n; i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end());
	int minValue = INF;

	int left = 0, right = n - 1;
	int minLeft = 0, minRight = 0;

	while (left != right)
	{
		int sum = vec[left] + vec[right];

		if (minValue > abs(sum))
		{
			minValue = abs(sum);
			minLeft = vec[left];
			minRight = vec[right];
		}

		if (sum > 0)
			right--;
		else
			left++;
	}

	cout << minLeft << ' ' << minRight;

	return 0;
}