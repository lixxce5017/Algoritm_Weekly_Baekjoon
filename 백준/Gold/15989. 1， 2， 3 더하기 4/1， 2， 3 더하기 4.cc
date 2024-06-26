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
int dp[10003];
int sum[3] = { 1,2,3 };
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int k;
	cin >> k;
	while (k)
	{
		int n;
		cin >> n;
		dp[0] = 1;

		for (int i = 0; i < 3; i++)
		{
			for (int j = sum[i]; j <= n; j++)
			{
				dp[j] = dp[j] + dp[j - sum[i]];
			}
		}

		cout << dp[n]<<"\n";
		for (int i = 0; i <= 10001; i++)
		{
			dp[i] = 0;
		}
		k--;
	}

}
