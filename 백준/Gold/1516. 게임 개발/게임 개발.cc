#include <iostream>
#include <vector>
#include<queue>
using namespace std;

vector<vector<int>> Arr;
vector<int> indegree;
vector<int> selfBuild;
vector<int>result;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	Arr.resize(n + 1);
	indegree.resize(n + 1);
	selfBuild.resize(n + 1);
	result.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> selfBuild[i];
		while (true)
		{
			int q;
			cin >> q;
			if (q == -1)
				break;
			else
			{
				Arr[q].push_back(i);
				indegree[i]++;
			}
		}
	}
	queue<int> myque;
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
		{
			myque.push(i);
		}
	}
	while (!myque.empty())
	{
		int now = myque.front();
		myque.pop();
		for (int next : Arr[now])
		{
			indegree[next]--;
			result[next] = max(result[next], result[now] + selfBuild[now]);
			if (indegree[next] == 0)
				myque.push(next);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << result[i] + selfBuild[i] << "\n";
	}



	
}