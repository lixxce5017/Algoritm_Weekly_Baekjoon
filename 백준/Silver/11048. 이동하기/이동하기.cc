#include <iostream>

using namespace std;
long long dp[1003][1003] = { 0, };
long long arr[1003][1003] = { 0, };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	
	int n,m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = max(dp[i][j], max(dp[i][j-1],dp[i-1][j]))+arr[i][j];
		}
	}
	cout << dp[n][m];
}
