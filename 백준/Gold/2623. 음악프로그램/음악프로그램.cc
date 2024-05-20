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
	
	cin >> n>> m;
	vector<vector<int>>arr(n + 1);
	vector<int>inDegree(n + 1, 0);
	vector<int>result;
	while (m--) {
		int t;
		int s1, s2;
		cin >> t;
		if (t == 0) continue;
		cin >> s1;
		if (t == 1) continue;

		for (int i = 0; i < t - 1; i++) {
			cin >> s2;
			arr[s1].push_back(s2);
			inDegree[s2]++;
			s1 = s2;
		}
	}
	
	queue<int>myque;
	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0)
		{
			myque.push(i);
		}
	}
	while (!myque.empty())
	{
		int now=myque.front();
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
	if (result.size() == n)
	{
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << "\n";
		}
	}
	else
	{
		cout << 0;
	}
	return 0;
}