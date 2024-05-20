#include <iostream>
#include <queue>
#include <tuple>
#include<string>
#include<queue>
#include<climits>
#include<string>
#include <memory.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>>arr(n+1);
	vector<int>inDegree(n+1,0);
	vector<int>result;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		inDegree[b]++;
	}
	
	priority_queue<int, vector<int>, greater<int>>myque;
	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0)
		{
			myque.push(i);
		}
	}
	while (!myque.empty())
	{
		int now=myque.top();
		myque.pop();
		result.push_back(now);
		for (auto i : arr[now])
		{
			
			inDegree[i]--;
			if (inDegree[i] == 0)
			{
				myque.push(i);
			}
		}
	}
	for (int i = 0; i < result.size();i++)
	{
		cout << result[i] << "\n";
	}
	return 0;
}