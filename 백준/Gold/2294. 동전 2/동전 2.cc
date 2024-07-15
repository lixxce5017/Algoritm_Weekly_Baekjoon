#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<queue>
#include<stack>
#include<tuple>
#include<limits.h>
#include<queue>
#include<cstring>
#include<tuple>

using namespace std;
int dp[10003];
int arr[103];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= k; i++)
	{
		dp[i] = 10003;
	}
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = arr[i]; j <= k; j++)
		{
			dp[j] = min(dp[j], dp[j-arr[i]] + 1);
		}
	}
	if (dp[k] == 10003)
	{
		cout << -1;
		return 0;
	}
	cout << dp[k]-1;
}