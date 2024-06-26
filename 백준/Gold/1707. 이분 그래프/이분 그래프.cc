#include <iostream>
#include<vector>
using namespace std;
vector<vector<int>> Arr;
vector<bool>visitied;
vector<int> result;
bool trueth;

void dfs(int node)
{
	visitied[node] = true;
	for (auto i : Arr[node])
	{
		if (!visitied[i])
		{
			//rsult[node]+1%i;
			result[i] = (result[node]+1) % 2;
			dfs(i);
		}
		else if (result[i] == result[node])
		{
			trueth = false;
		}
	}
	

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int n, m;
		cin >> n >> m;
		Arr.resize(n + 1);
		visitied.resize(n + 1);
		trueth = true;
		result.resize(n + 1);
		for (int j = 0; j < m; j++)
		{
			int a, b;
			cin >> a >> b;
			Arr[a].push_back(b);
			Arr[b].push_back(a);
		}

		for (int w = 1; w <= n;w++)
		{
			if (trueth)
			{
				dfs(w);
			}
			else
			{
				break;
			}
		}
		if (trueth)
		{
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
		for (int r = 0; r <= n; r++)
		{
			Arr[r].clear();
			visitied[r] = false;
			result[r] =0;
		}
	}

}

