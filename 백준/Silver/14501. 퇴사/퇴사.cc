#include <iostream>
#include <string>
#include<math.h>
#include<vector>
using namespace std;


int main() {
	
	int n;
	cin >> n;
	int time[20] = { 0, };
	int val[20] = { 0, };
	int dp[20] = { 0, };
	for (int i = 1; i <= n; i++)
	{
		cin >> time[i] >> val[i];
	}
	for (int i = n; i >= 1; i--)
	{
		int line = i + time[i];
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