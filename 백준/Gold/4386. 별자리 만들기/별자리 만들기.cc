#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<queue>
#include<stack>
#include<tuple>
#include<cmath>
#include<limits.h>
using namespace std;
vector<int>parent;
vector<pair<float, float>> arr;
typedef pair<double, pair<int, int>> Edge;
void union_set(int a, int b);
int find(int a);
priority_queue<Edge, vector<Edge>, greater<Edge>> myque;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		
		double a, b;
		cin >> a >> b;
		arr.push_back(make_pair( a,b ));
	}
	parent.resize(n + 1);
	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size(); j++)
		{
			if (i != j)
			{
				double dis = sqrt(pow(arr[i].first - arr[j].first, 2) + pow(arr[i].second - arr[j].second, 2));
				myque.push(Edge{ dis,{i+1,j+1} });
			}
		}
	}
	int use = 0;
	double result = 0;
	while (use < n - 1)
	{
		Edge now = myque.top();
		double v = now.first;
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
	cout.precision(3);
	cout << result;
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