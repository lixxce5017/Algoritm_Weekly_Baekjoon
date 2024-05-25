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
bool power_plant[1003];
typedef pair<int, pair<int, int>> Edge;
void union_set(int a, int b);
int find(int a);
priority_queue<Edge, vector<Edge>, greater<Edge>> myque;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m,k;

	cin >> n >> m>>k;
	for (int i = 0; i < k; i++)
	{
		int temp;
		cin >>temp;
		power_plant[temp] = true;
	}
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
	for (int i = 1; i <= n; i++)
	{
		if (power_plant[i] == true)
		{
			parent[i] = 0;
		}
	}
	int use = 0;
	int result = 0;
	//유니온 파인드 대신 dfs가 필요하다
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
			result += v;

		}
	}
	cout << result;
}
//무조건 조상이 발전기로 매칭되게
//유파를 바꿔도 되지 않을까?
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