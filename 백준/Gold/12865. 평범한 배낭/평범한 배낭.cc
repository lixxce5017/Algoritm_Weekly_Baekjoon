#include<iostream>
#include<vector>
using namespace std;

int W[103] = { 0, };
int V[103] = { 0, };
int dp[103][100004] = { 0, };
int main(void)
{

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,K;
	cin >> n>>K;
	 
	for (int i = 1; i <= n; i++)
	{
		cin >> W[i]>>V[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= K; j++)
		{	//베낭에 넣는 경우
			if (W[i] <=j)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i-1][j - W[i]] + V[i]);;
			}
			//안 넣는 경우
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	cout << dp[n][K];
	return 0;
}