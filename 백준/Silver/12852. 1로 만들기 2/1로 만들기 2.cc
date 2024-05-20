#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>
using namespace std;
int dp[1000001];


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	for (int i =2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0)
		{
			dp[i] = min(dp[i / 2] + 1, dp[i]);
		
		}
		if (i % 3 == 0)
		{
			dp[i] = min(dp[i / 3]+1, dp[i]);
			
		}
	}
	cout << dp[n]<<"\n";

	while (n !=1)
	{
		cout << n << " ";
		if (dp[n] == dp[n - 1] + 1)
		{
			n = n - 1;
		}
		else if (n % 2 == 0 && dp[n / 2] + 1 == dp[n])
		{
			n = n / 2;
		}
		else if (n % 3 == 0 && dp[n / 3] + 1 == dp[n])
		{
			n = n / 3;
		}
	}
	cout << 1;
}
