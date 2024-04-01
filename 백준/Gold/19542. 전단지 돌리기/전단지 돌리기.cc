#include <iostream>
#include <vector>
using namespace std;
#include<queue>
bool visited2[100003];
int visitied[100003] = { 0, };
vector<vector<int>> arr;
int n, s, d;
int ans = 0;
#define mysecond 2
int dfs(int now, int before)
{

	for (auto i : arr[now])
	{
		if (visited2[i] == false)
		{
			visited2[i] = true;
			visitied[now] = max(visitied[now], dfs(i, now));
		}
	}
	return visitied[now] + 1;
}
int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> s >> d;
	arr.resize(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	visited2[s] = true;
	dfs(s, -1);
	for (int i = 1; i <= n; i++)
	{
		if (visitied[i] >= d && i != s) ans++;
	}
	cout << ans * 2;
}