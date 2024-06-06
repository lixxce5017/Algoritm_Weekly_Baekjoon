#include <iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<vector<pair<int,int>>>arr;
bool visitied[1003];
int res = 0;
void dfs(int node, int end, int cnt)
{
	visitied[node] = true;
	if (node == end)
	{
		res = cnt;
		return;
	}
	for (auto i:arr[node])
	{
		int temp = i.first;
		if (visitied[temp] == false)
		{
			dfs(temp, end, cnt+i.second);
		}
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	arr.resize(n + 1);
	for (int i = 0;i < n - 1;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back(make_pair(b, c));
		arr[b].push_back(make_pair(a, c));
	}
	for (int i = 0;i < m;i++)
	{
		int start, end;
		res = 0;
		cin >> start >> end;
		dfs(start, end,0);
		memset(visitied, false, sizeof(visitied));
		cout << res<<"\n";
	}
	return 0;
}