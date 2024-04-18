#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<queue>
#include <climits>
#include<tuple>
#include<limits.h>
using namespace std;

vector<bool>visitied;
typedef pair<int, int> Node;
priority_queue<Node, vector<Node>, greater<Node>>qq;
vector<long>result;
long long res[100003];
long long res2[100003];
long long res3[100003];
vector <vector<Node>>arr;
void Distra(int val, int node);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	int n, m;
	cin >> n;
	int a, b, c;
	cin >> a >> b >> c >> m;
	result.resize(n + 1);
	visitied.resize(n + 1);
	arr.resize(n + 1);
	fill(visitied.begin(), visitied.end(), false);
	fill(result.begin(), result.end(), LONG_MAX);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back(Node(b, c));
		arr[b].push_back(Node(a, c));
	}
	Distra(0, a);
	for (int i = 1; i <= n; i++)
	{
		res[i] = result[i];
	}
	fill(visitied.begin(), visitied.end(), false);
	fill(result.begin(), result.end(), LONG_MAX);

	Distra(0, b);
	for (int i = 1; i <= n; i++)
	{
		res2[i] = result[i];
	}
	fill(result.begin(), result.end(), LONG_MAX);
	fill(visitied.begin(), visitied.end(), false);
	Distra(0, c);
	for (int i = 1; i <= n; i++)
	{
		res3[i] = result[i];
	}
	int maxx = -1;
	int maxid = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i == a || i == b || i == c)
			continue;
		int now = min(res[i], min(res2[i], res3[i]));
		if (maxx <now)
		{
			maxid = i;
			maxx = now;
		}
	}
	cout << maxid;

}

void Distra(int val, int node)
{

	qq.push(Node(0, node));
	//여기 헷갈림
	result[node] = 0;

	while (!qq.empty())
	{
		Node now = qq.top();
		qq.pop();
		if (visitied[now.second])
		{
			continue;
		}
		visitied[now.second] = true;

		for (auto i : arr[now.second])
		{
			int cur_node = i.first;
			int cur_val = i.second;
			if (result[cur_node] > cur_val + result[now.second])
			{
				result[cur_node] = cur_val + result[now.second];
				qq.push(Node(result[cur_node], cur_node));
			}
		}
	}

}
