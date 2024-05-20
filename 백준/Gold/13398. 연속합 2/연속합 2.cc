#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int dp[100003][2];
int arr[100003];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	int max1 = arr[1];
	dp[1][1] = arr[1];
	dp[1][0] = arr[1];
	for (int i = 2; i <= n; i++)
	{
		dp[i][0]= max(arr[i], arr[i] + dp[i - 1][0]);
		dp[i][1] = max(dp[i-1][0], dp[i-1][1] + arr[i]);
		max1 = max(max1,max(dp[i][1],dp[i][0]));
	}


	cout << max1;
}
