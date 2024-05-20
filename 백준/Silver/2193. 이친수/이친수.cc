#include<iostream>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long long dp[150] = { 0, };
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	dp[4] = 3;

	for (int i = 5; i <= 100; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	
	int a;
	cin >> a;
	cout << dp[a];
}