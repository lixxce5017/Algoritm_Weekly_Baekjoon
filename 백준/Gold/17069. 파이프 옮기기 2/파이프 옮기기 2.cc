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
int n, m;
int Map[50][50];
long long dp[50][50][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> Map[i][j];

		}
	}
	dp[1][2][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			if (Map[i][j] == 1)
				continue;
			//가로니까 이전에서 오는 가로와 대각선의 값
			if (Map[i][j - 1] == 0)
				dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];
			if (Map[i - 1][j] == 0)
				dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][2];
			if (Map[i - 1][j-1] == 0&&Map[i-1][j]==0&&Map[i][j-1]==0)
				dp[i][j][2] += dp[i - 1][j-1][1] + dp[i - 1][j-1][2]+dp[i-1][j-1][0];
		}
	}

	cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
}