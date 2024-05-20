#include<iostream>
#include<algorithm>
using namespace std;

int N;
int k;
int val[10001] = { 0, };
int time[1003] = { 0, };
int dp[1001][10003] = { 0, };


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	cin >> k;
	for (int i = 1; i <=k; i++)
	{
		cin >> val[i] >> time[i];
	}

	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (j >= time[i])
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - time[i]] + val[i]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[k][N];
}