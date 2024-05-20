#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n>>k;
	int dp[10001] = { 0, };
	int coin[103];
	for (int i = 1; i <= n; i++)
	{
		cin >> coin[i];
	}
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = coin[i]; j <= k+1; j++)
		{
			dp[j] = dp[j] + dp[j - coin[i]];
	
		}
		
	}
	cout << dp[k];
	return 0;
}