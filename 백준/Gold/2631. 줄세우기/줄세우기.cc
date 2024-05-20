#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dp[1000001] = { 0, };
int arr[1000001] = { 0, };
int n, k;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	int maxx = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			

			}
			maxx = max(maxx, dp[i]);
		}
	}
	cout << n-maxx;
}