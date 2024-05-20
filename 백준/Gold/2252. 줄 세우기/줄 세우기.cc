#include<vector>
#include<iostream>
#include<queue>
using namespace std;
static int n, m;
static vector<bool>visitied;
static vector<vector<int>> arr;
static vector<int>degree;
static vector<int>result;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	cin >> n >> m;
	arr.resize(n + 1);
	
	degree.resize(n + 1);
	fill(visitied.begin(), visitied.end(), false);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		degree[b]++;
	}
	queue<int>myque;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (degree[i] == 0)
		{
			myque.push(i);
			cnt++;
		}
	}
	if (cnt == 0)
	{
		cout << "-1";
		return 0;
	}
	while (!myque.empty())
	{
		int now = myque.front();
		result.push_back(now);
		myque.pop();

		for (auto i : arr[now])
		{
			degree[i]--;
			if (degree[i]==0)
			{
				myque.push(i);
			}
		}
		
	}
	if (result.size() == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << result[i] << " ";
		}
	}
	else
		cout << "-1"; return 0;
}	