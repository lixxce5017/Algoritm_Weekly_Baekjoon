#include <iostream>
#include <vector>
using namespace std;
#include<queue>
int visitied[100003] = { 0, };
vector<vector<int>> arr;
int n, s, d;
int ans = 0;
int dfs(int now,int before)
{

	for (auto i : arr[now])
	{
		if (before!=i)
		{
			visitied[now] = max(visitied[now], dfs(i, now) + 1);
		}
	}
	if (visitied[now] >= d && now != s) ans++;
	return visitied[now];
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

	dfs(s,-1);
	cout << ans * 2;
}