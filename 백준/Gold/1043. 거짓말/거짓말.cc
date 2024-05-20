#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int parents[51];
vector<int> know;
vector<vector<int> > v(50);
int cnt = 0;

int find(int a)
{
	if (a == parents[a])
	{
		return a;
	}
	return parents[a] = find(parents[a]);
}

void unionFind(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
	{
		parents[b] = a;
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cout.tie(NULL);
	int n,m,k;
	cin >> n>>m>>k;
	know.resize(k + 1);
	for (int i = 0; i < k; i++)
	{
		cin >> know[i];
	}
	for (int i = 0; i < n; i++) parents[i] += i;
	for (int i = 0; i < m; i++)
	{
		int NodeNum;
		cin >> NodeNum;
		for (int j = 0; j <NodeNum; j++)
		{
			int q;
			cin >> q;
			v[i].push_back(q);
		}
	}
	for (int i = 0; i < m; i++)
	{
		int first = v[i][0];
		for (int j = 1; j < v[i].size(); j++)
		{
			unionFind(first, v[i][j]);
		}
	}

	for (int i = 0; i < m; i++)
	{
		bool isTrue = true;
		int cur = v[i][0];

			for (int j = 0; j < k; j++)
			{
				if (find(cur) == find(know[j]))
				{
					isTrue = false;
					break;
				}
			}
		if (isTrue == true)
		{
			cnt++;
		}
	}
	cout << cnt;
}