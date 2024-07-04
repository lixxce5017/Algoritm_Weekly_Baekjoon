#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<queue>
#include<stack>
#include<tuple>
#include<limits.h>
#include<queue>
#include<cstring>
using namespace std;
int arr[103][103];
int check[103][103];
bool visitied[103][103];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int n, m;
void dfs(int x, int y)
{
	visitied[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m)
		{
			if (visitied[nx][ny] == false)
			{
				if (arr[nx][ny] == 0)
				{
					visitied[nx][ny] = true;
					dfs(nx, ny);
				}
				else if (arr[nx][ny] == 1)
				{
					check[nx][ny] += 1;
				}
			}
		}
	}
}
int melt()
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (check[i][j] >=2)
			{
				cnt++;
				arr[i][j] = 0;
			}
		}
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	int year = 1;
	while (1)
	{
		memset(visitied, 0, sizeof(visitied));
		memset(check, 0, sizeof(check));
		dfs(0,0);
		int res = melt();
		if (res == 0)
		{
			cout << year-1;
			return 0;
		}
		year++;
	}

}