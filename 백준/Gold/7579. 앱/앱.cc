#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

int val[103];
int weight[103];
int n, m;
int  dp[103][10001];
int sum = 0;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> weight[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		cin >> val[i];
		sum += val[i];
	}




	for (int i = 1; i <=n; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			if (j - val[i] >= 0)
			{
				dp[i][j] = max(dp[i][j],dp[i - 1][j-val[i]] + weight[i]);
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	
	}

	for (int i = 0; i <= sum; i++)
	{
		
		if (dp[n][i] >= m)
		{
			cout << i;
			break;
		}
	}
}


