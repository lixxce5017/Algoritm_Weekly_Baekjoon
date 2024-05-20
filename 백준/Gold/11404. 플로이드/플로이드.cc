#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<queue>
#include <climits>
#include<tuple>
#include<limits.h>
using namespace std;

int mdistance[101][101];
long INF = 987654321;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	int n, m;
	cin >> n>>m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				mdistance[i][j] = 0;
			}
			else
			{
				mdistance[i][j] = INF;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (mdistance[a][b] > c)
		{
			mdistance[a][b] = c;
		}
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i= 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (mdistance[i][j] > mdistance[k][j] + mdistance[i][k])
				{
					mdistance[i][j] = mdistance[k][j] + mdistance[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << (mdistance[i][j] != INF ? mdistance[i][j] : 0) << " ";
			
		}
		cout << "\n";
	}
}
