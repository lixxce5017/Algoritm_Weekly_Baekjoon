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
char arr[31][31];
bool visitied[31][31];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int n, m;
int cnt = 0;
int res=INT_MAX;
//실수한 부분 
//	if(check.size()>=1)
// 안가는것을 고려하지 않았음
// 이외엔 그냥 2048,구슬탈출 하위호완 중력 문제 느낌
void dfs(int x, int y,int count,int dist)
{
	if (count == cnt)
	{
		res = min(dist, res);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
			int count_jum = 0;
			int nx = x;
			int ny = y;
			vector<pair<int, int>> check;
			while (1)
			{
				 nx += dx[i];
				 ny += dy[i];
				if (nx >= 0 && ny >= 0 && nx < n && ny < m&&visitied[nx][ny] == false && arr[nx][ny] == '.')
				{
					visitied[nx][ny] = true;
					count_jum++;
					check.push_back({ nx,ny });
				}
				else
				{
					nx -= dx[i];
					ny -= dy[i];
					break;
				}
			}
			if (check.size() >= 1)
			{
				dfs(nx, ny, count + count_jum, dist + 1);
			}
			for(auto k:check)
			{
				visitied[k.first][k.second] = false;
			}
			check.clear();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int q = 1;
	while (cin>>n>>m)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == '.')
				{
					cnt++;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == '.')
				{
					visitied[i][j] = true;
					//cout << "start" << "\n";
					dfs(i, j, 1, 0);
					visitied[i][j] = false;
				}
			}
		}
		if (res == INT_MAX)
			cout << "Case " << q << ": " << -1 << "\n";
		else
			cout << "Case " << q<< ": " << res << "\n";
		res = INT_MAX;
		cnt = 0;
		q++;
		memset(visitied, false, sizeof(visitied));
		memset(arr, 0, sizeof(arr));
	}
}