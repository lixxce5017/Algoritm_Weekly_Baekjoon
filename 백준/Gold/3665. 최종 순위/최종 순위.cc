#include <iostream>
#include <queue>
#include <tuple>
#include<string>
#include<queue>
#include<climits>
#include<string>
#include <memory.h>
using namespace std;
int team[501];
int order[501];
int indegree[501];
bool adj[501][501];
int n;
vector<int>result;
int change;
int topolzySort()
{
	queue<int>myque;
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
		{
			myque.push(i);

		}
	}
	while (!myque.empty())
	{
		if (myque.size() > 1)
		{
			return 0;
		}
		int now = myque.front();
		myque.pop();
		result.push_back(team[now]);
		if (result.size() == n)
		{
			return 1;
		}
		for (int i = 1; i <= n; i++)
		{
			if (adj[now][i] == false)continue;
			adj[now][i] = false;
			indegree[i]--;
			if (indegree[i] == 0)
			{
				myque.push(i);
			}
		}

	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t>0)
	{
		
		cin >> n;
		result.clear();
		memset(team, 0, sizeof(team));
		memset(order, 0, sizeof(team));
		memset(adj, 0, sizeof(adj));
		memset(indegree, 0, sizeof(indegree));
		for (int i = 1; i <= n; i++)
		{
			cin >> team[i];
			order[team[i]] = i;
		}
		
		for (int i = 1; i < n; i++)
		{
			for (int j = i+ 1; j <= n; j++)
			{
				adj[i][j] = true;
				indegree[j]++;
			}
		}
		cin >> change;
		for (int i = 0; i < change; i++)
		{
			int a, b;
			cin >> a >> b;
			if (order[a] > order[b])
				swap(a, b);

			int node_a = order[a];
			int node_b = order[b];

			adj[node_a][node_b] = false;
			indegree[node_b]--;

			adj[node_b][node_a] = true;
			indegree[node_a]++;

		}
		int ans = topolzySort();
		if (ans == -1)
		{
			cout << "IMPOSSIBLE";
		}
		else if (ans == 0)
		{
			cout << "?";
		}
		else if(ans==1){
			int length = result.size();
			for (int j = 0; j < length; j++)
			{
				cout << result[j] << " ";
			}
		}
		cout << "\n";
		t--;
	}

}