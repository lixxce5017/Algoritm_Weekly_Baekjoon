#include<iostream>
#include<algorithm>
#include<string>
#include<deque>
#include<queue>
#include<stack>
#include<tuple>
#include<limits.h>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
//vector<vector<int>> arr;
vector<vector<int>> arr;
bool visitied[53];
int dfs(int node)
{
	vector<int> val;
	for (auto i : arr[node])
	{
		if (visitied[i] == false)
		{
			visitied[i] = true;
			val.push_back(dfs(i));
		}
	}
	sort(val.begin(), val.end(), greater<int>());
	int time = 1;
	int cnt = 0;
	for (int i = 0; i < val.size(); i++)
	{
		val[i] += time;
		time++;
		cnt = max(val[i], cnt);
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	arr.resize(n + 1);
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (num == -1)
		{
			continue;
		}
		else
		{
			arr[num].push_back(i);
			arr[i].push_back(num);
		}
	}
	visitied[0] = true;
	cout<<dfs(0);
}