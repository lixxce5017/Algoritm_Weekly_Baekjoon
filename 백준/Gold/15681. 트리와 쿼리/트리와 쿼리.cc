#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<vector<int>> arr;
int dp[1000003] = { 0, };
bool visitied[1000003];
vector<int> qurr;
int dfs(int n)
{
	if (visitied[n] == true)
	{
		return dp[n];
	}
	visitied[n] = true;
	dp[n] = 1;
	for (auto i : arr[n])
	{
		
		if (visitied[i] == false)
		{
			dp[n] = dp[n] + dfs(i);
		}
	}
	return dp[n];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,root,qury;
	cin >> n>>root>> qury;
	arr.resize(n + 1);
	for (int i = 0; i < n-1; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	dfs(root);
	qurr.resize(qury + 1);
	for (int i = 1; i <= qury; i++)
	{
		int temp;
		cin >> temp;
		cout << dp[temp]<<"\n";
	}
	
	
	
}