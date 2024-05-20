#include <iostream>

using namespace std;
int dp[100004] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);

	int n;
	cin >> n;
	dp[0] = 1;
	dp[1] = 3;
	dp[2] = 7;
	dp[3] = 17;
	dp[4] = 41;
	for (int i = 5; i <= n; i++)
	{
		dp[i] = ((dp[i - 1] * 2) + dp[i - 2])%9901;
	}
	cout << dp[n];
}
