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
char arr[10003][503];
bool visitied[10003][503];
int dx[3] = { -1,0,1};
int dy[3] = { 1,1,1};
int n, m;
int cnt = 0;
int res=0;

bool dfs(int x, int y)
{
	if (y == m - 1)
	{
		res++;
		return true;
	}
	bool stop = false;
	for (int i = 0; i < 3; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;		
		if (nx >= 0 && ny >= 0 && nx < n && ny < m)
		{
			if (visitied[nx][ny] == false && arr[nx][ny] == '.')
			{
				visitied[nx][ny] = true;
				bool stop=dfs(nx, ny);
				if (stop)
					return true;
			}
		}
		
	}
	return false;
}

int main()
{
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
			arr[i][j] = s[j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (visitied[i][0] == false && arr[i][0] == '.')
		{
			visitied[i][0] = true;
			dfs(i, 0);
		}
	}
	cout << res;
}