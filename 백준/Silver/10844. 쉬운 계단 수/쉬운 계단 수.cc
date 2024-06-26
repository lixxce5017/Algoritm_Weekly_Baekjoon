#include <iostream>
#include <string>
#include<math.h>
#include<vector>
#include<queue>
#include <climits>
#include<algorithm>
#include<climits>
#include<tuple>
#include<limits.h>
using namespace std;
int dp[101][12];
//0~9
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= 9; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
			{
				dp[i][j] = (dp[i - 1][j+1])% 1000000000;
			}
			else if (j == 9)
			{
				dp[i][j] = (dp[i - 1][j - 1]) % 1000000000;
			}
			else
			{
				dp[i][j] =( dp[i - 1][j - 1] + dp[i - 1][j + 1])% 1000000000;
			}
	
			
		}
	}
	long long ans = 0;
	for (int i = 0; i < 10; i++)
	{
		ans = ans + dp[n][i];
	}
	cout << ans % 1000000000;

}
