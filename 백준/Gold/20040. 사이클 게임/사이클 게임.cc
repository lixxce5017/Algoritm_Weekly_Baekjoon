#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <math.h>
#include<tuple>
#include<queue>;
using namespace std;
int parent[500003];
int find(int a);
void uinon_set(int q, int w);
bool Check_Set(int q, int w);
void uinon_set(int q, int w)
{
	int a = find(parent[q]);
	int b = find(parent[w]);
	if (a != b)
	{
		if (a >= b)
		{
			parent[a] = b;
		}
		else
		{
			parent[b] = a;
		}
	}

}
bool Check_Set(int q, int w)
{
	int a = find(parent[q]);
	int b = find(parent[w]);
	if (a == b)
		return true;
	else
		return false;

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
int main()
{	//R이 34, 23 green, blue 18
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		 cin>>a >> b;
		
		if (Check_Set(a, b) == true)
		{
			cout<<i + 1;
			return 0;
		}
		uinon_set(a, b);
	}
	
	cout << 0;
	
}