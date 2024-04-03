#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
long long dp[100003]= { 0, };
long long arr[100003]= { 0, };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	int max1 = -INT_MAX;
	int max2 = -INT_MAX;

	for (int i = 1; i <= n; i++)
	{
		dp[i] = max(arr[i], arr[i] + dp[i - 1]);
		if (max1 < dp[i])
		{
			max1 = dp[i];
		}
	}
	cout << max1;
}
