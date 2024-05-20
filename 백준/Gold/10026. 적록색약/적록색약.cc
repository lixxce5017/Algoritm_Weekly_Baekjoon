#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <math.h>
using namespace std;
int MAP[101][101];
bool visitied[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1, 0,0 };
int ans1 = 0;
int ans2 = 0;
int n;
void dfs(int x, int y, int Val)
{
	if (visitied[x][y] == true)
	{
		return;
	
	}
	visitied[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx >= 0 && ny >= 0 && nx < n && ny < n)
		{
			if (MAP[nx][ny] == Val)
			{
				dfs(nx, ny, Val);
			}
		}
	}

}
int main()
{	//R이 34, 23 green, blue 18
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			 MAP[i][j]=s[j]-'0';
		}
	}
	//일반
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visitied[i][j] == false)
			{
				cnt++;
				dfs(i, j, MAP[i][j]);
			}
		}
	}
	ans1 = cnt;
	cnt = 0;
	memset(visitied, false, sizeof(visitied));
	//적록색약
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (MAP[i][j] == 34||MAP[i][j]==23)
			{
				MAP[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visitied[i][j] == false)
			{
				cnt++;
				dfs(i, j, MAP[i][j]);
			}
		}
	}
	cout << ans1 <<" "<< cnt;
}