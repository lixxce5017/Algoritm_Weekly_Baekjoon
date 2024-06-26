#include <iostream>
#include <string>
#include<math.h>
#include<vector>
#include<queue>
#include <climits>
#include<algorithm>
#include<climits>
#include<tuple>
#include<limits.h>
using namespace std;
int n, m, k;
int degree[10003] = { 0, };
queue<int>q;
int t[10002];
int result[10001];
vector<int> adj[10002];

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i];
		int num;
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			int temp;
			cin >> temp;
			adj[temp].push_back(i);
			degree[i]++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (degree[i] == 0)
		{
			q.push(i);
		}
		result[i] = t[i];
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < adj[cur].size(); i++)
		{
			int next = adj[cur][i];
			degree[next]--;
			result[next] = max(result[next], result[cur]+t[next]);
	
			if (degree[next] == 0)
			{
				q.push(next);
			}
		}
	}
	int ans = -1;
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans,result[i]);
	}
	cout << ans;

}
