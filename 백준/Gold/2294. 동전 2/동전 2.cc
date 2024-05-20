#include<iostream>
using namespace std;
int coin[103] = { 0, };
int dp[10003];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> coin[i];
	}
	for (int i = 1; i <= k; i++)
	{
		dp[i] = 10003;
	}
	//도대체 왜 coin[1]=1일때는 33에서 틀릴까요? 이해가 안가요
	coin[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = coin[i]; j <= k; j++)
		{
			
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
			
		}
	}
	if (dp[k] == 10003)
	{
		cout << -1;
		
	}
	else
	{
		cout << dp[k];
	}
	return 0;
}
	

