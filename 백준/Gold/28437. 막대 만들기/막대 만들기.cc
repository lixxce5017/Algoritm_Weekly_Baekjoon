#include<iostream>
using namespace std;
int n, q;
long long dp[100003];
long long ans[100003];
int maxx = 0;
int main()
{
	int n,k;
	
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		int temp;
		cin >> temp;
		dp[temp] += 1;
	}
	//1 squre
	cin >> k;
	/*for (int i = 2;i <= k;i++)
	{
		dp[i]+=1;
	}*/

	for (int i = 0;i < k;i++)
	{
		cin >> ans[i];
	}	
	for (int i = 1;i <= 100003;i++)
	{
		for (int j = i * 2;j <= 100003;j += i)
		{
			dp[j] += dp[i];
		}
	}
	for (int i = 0;i < k;i++)
	{
		cout << dp[ans[i]] << " ";
	}
	return 0;
}