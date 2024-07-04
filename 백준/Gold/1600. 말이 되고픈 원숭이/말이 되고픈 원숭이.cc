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
#include<tuple>
using namespace std;
typedef tuple<int, int, int, int> t;
int arr[205][205];
bool visitied[205][205][40];
int dx[4] = {0,0,1,-1};
int dy[4] = { 1,-1,0,0};
int horse_d[8][2] = { {1,2},{2,1},{1,-2},{2,-1},{-1,2},{-2,1},{-1,-2},{-2,-1} };
int k,n, m;
int cnt = 0;
int res=0;
queue<t>que;
//입력 n,m 바껴들어옴 조심
//벽부수고 이동하기 1,2 소년점프 비슷한 문제
int bfs(int x, int y)
{
	visitied[x][y][0] = true;
	//visitied[x][y][1] = true;
	que.push({ 0,0,0,0});
	while (!que.empty())
	{
		t temp = que.front();
		int x = get<0>(temp);
		int y = get<1>(temp);
		int cnt = get<2>(temp);
		int use = get<3>(temp);
		que.pop();
		if (x == n - 1 && y == m - 1)
		{
			return cnt;
		}
		if (use < k)
		{
			for (int i = 0; i < 8; i++)
			{
				int nx = horse_d[i][0] + x;
				int ny = horse_d[i][1] + y;
				if (nx >= 0 && ny >= 0 && nx < n && ny < m)

				{
					if (visitied[nx][ny][use + 1] == false && arr[nx][ny] == 0)
					{
						que.push({ nx, ny, cnt + 1, use + 1 });
						visitied[nx][ny][use + 1] = true;
					}
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i]+x;
			int ny = dy[i] + y;
			if (nx >= 0 && ny >= 0 && nx < n && ny < m)
			{
				if (visitied[nx][ny][use] == false && arr[nx][ny] == 0)
				{
					que.push({ nx, ny, cnt + 1, use});
					visitied[nx][ny][use] = true;
				}
			}
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> k>>m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << bfs(0, 0);

}