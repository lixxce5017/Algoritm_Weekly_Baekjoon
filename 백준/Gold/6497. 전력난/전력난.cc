#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<queue>
#include<stack>
#include<tuple>
#include<limits.h>
using namespace std;
vector<int>parent;

typedef pair<int, pair<int, int>> Edge;
void union_set(int a, int b);
int find(int a);
priority_queue<Edge, vector<Edge>, greater<Edge>> myque;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	while (n != 0 && m != 0)
	{

		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			myque.push(Edge{ c,{a,b} });
		}
		parent.resize(n + 1);
		for (int i = 0; i <= n; i++)
		{
			parent[i] = i;
		}

		int use = 0;
		int result = 0;
		int result2 = 0;
		while (!myque.empty())
		{
			Edge now = myque.top();
			int v = now.first;
			int s = now.second.first;
			int e = now.second.second;
			myque.pop();
			if (find(s) != find(e))
			{
				union_set(s, e);
				use++;

			}
			else
			{
			result += v;
			}
		}
		cout << result << "\n";
		cin >> n >> m;
	}

}
void union_set(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
	{
		parent[b] = a;
	}
}
int find(int a)
{
	if (a == parent[a])
	{
		return a;
	}
	else
	{
		return parent[a] = find(parent[a]);
	}
}