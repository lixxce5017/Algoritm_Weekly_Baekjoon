#include <iostream>
#include <string>
#include<math.h>
#include<vector>
using namespace std;

long long timee[1500003] = { 0, };
long long val[1500003] = { 0, };
long long dp[1500003] = { 0, };
int main() {
	
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> timee[i] >> val[i];
	}
	for (int i = n; i >= 1; i--)
	{
		int line = i + timee[i];
		if (line >n+1)
		{
			dp[i] = dp[i + 1];
		}
		else
		{
			dp[i] = max(dp[i + 1], val[i] + dp[line]);
	
		}

	}
	cout << dp[1];
}