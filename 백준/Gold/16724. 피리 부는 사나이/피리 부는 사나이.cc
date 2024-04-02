#include <iostream>
#include <vector>
using namespace std;
#include<queue>
int visitied[1003][1003];
int n, s, d,m;
int ans = 0;
int arr[1003][1003];
void dfs(int x, int y,int cnt)
{
	visitied[x][y] = cnt;
	if (arr[x][y] == 1)
	{
		x += 1;
	}
	else if (arr[x][y] == 2)
	{
		x -= 1;
	}
	else if (arr[x][y] == 3)
	{
		y += 1;
	}
	else if (arr[x][y] == 4)
	{
		y -= 1;
	}
	if (x >= 0 && y >= 0 && x < n && y < m)
	{

		if (visitied[x][y] == cnt)
		{
			ans += 1;
		}
		if (visitied[x][y]) return;
		dfs(x, y, cnt);
	}
}
int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			if (s[j] == 'D')
			{
				arr[i][j] = 1;
			}
			else if (s[j] == 'U')
			{
				arr[i][j] = 2;
			}
			else if (s[j] == 'R')
			{
				arr[i][j] = 3;
			}
			else if (s[j] == 'L')
			{
				arr[i][j] = 4;
			}
		}
	}
	int cnt = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visitied[i][j] == 0)
			{
				dfs(i, j, cnt);
				cnt++;
			}
		}
	}
	cout << ans;
}