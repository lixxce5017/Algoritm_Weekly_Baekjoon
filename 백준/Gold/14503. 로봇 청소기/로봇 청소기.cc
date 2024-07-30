#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include<cstring>
#include<limits.h>
using namespace std;
bool visitied[53][53];
int arr[53][53];
//북 ,동,남,서
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m,sx,sy,d;
int cnt = 0;
//좌표 조심하자 반시계이다 그리고 들어온 곳 그대로 빼주면서 나가야한다
void dfs(int x, int y, int dir)
{
	if (visitied[x][y] == false)
	{
		cnt++;
		visitied[x][y] = true;
	}
	bool falg = false;
	for (int i = 0; i < 4; i++)
	{
		int dd = (dir-i+3) % 4;
		int nx = dx[dd] + x;
		int ny = dy[dd] + y;
		if (visitied[nx][ny] == false && arr[nx][ny] == 0)
		{
			falg = true;
			dfs(nx, ny, dd);
		}
	}
	if (falg == false)
	{
		if (arr[x -dx[dir]][y - dy[dir]] == 0)
		{
			dfs(x -dx[dir], y -dy[dir], dir);
		}
		else
		{
			cout << cnt;
			exit(0);
		}

	}
	return;
}
int main()
{
	cin >> n >> m>>sx>>sy>>d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	dfs(sx, sy, d);
}
