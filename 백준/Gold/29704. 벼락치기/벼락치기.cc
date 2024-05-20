#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int weight[1004] = { 0, };
int cost[5003] = { 0, };
long long dp[1003][1003] = { 0, };
long long maxval = 0;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> weight[i] >> cost[i];
		maxval += cost[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{	//넣는다
			if (j >= weight[i])
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + cost[i]);
			}
			//안넣는다
			else
			{
				dp[i][j] = dp[i - 1][j];
			}


		}


	}
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}*/
	cout << maxval-dp[n][k];
}