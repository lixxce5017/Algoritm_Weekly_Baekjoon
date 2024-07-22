#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstring>
using namespace std;
int n,m,k;
string pi[1004][1004];
char Map[1005][1005];
vector<tuple<int, int, int>> quer;
vector<pair<int,int>> dir;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	memset(Map, '.', sizeof(Map));
	for (int q = 0; q < k; q++)
	{
		int r, c;
		cin >> r >> c;

		dir.push_back({ r, c });
		for (int i = 0; i < r; i++)
		{
			cin >> pi[q][i];
		}
	}
	int q;
	cin >> q;
	for (int i = 0; i <q; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		quer.push_back(make_tuple(a-1, b, c));
	}
	for (int i = 0; i < q; i++)
	{
		int num = get<0>(quer[i]);
		int x = get<1>(quer[i]);
		int y = get<2>(quer[i]);
		int nx = 0;
		int ny = 0;
		
		int ex = dir[num].first;
		int ey = dir[num].second;
		for (int r = x; r < x + ex; r++)
		{
			for (int c = y; c< y+ ey; c++)
			{
				Map[r][c] = pi[num][nx][ny++];
			}
			ny = 0;
			nx++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << Map[i][j];
		}
		cout << "\n";
	}
	
}
