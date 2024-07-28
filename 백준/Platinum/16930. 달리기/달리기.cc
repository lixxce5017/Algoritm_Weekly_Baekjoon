#include <iostream>
#include <queue>
#include <tuple>
#include<string>
#include<queue>
#include<climits>
#include<string>
#include<queue>
using namespace std;
int n, m, k;
char arr[1003][1003];
queue<pair<int, int>> myq;
int visitied[1003][1003];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	myq.push({ sx-1,sy-1 });
	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { 1,-1,0,0 };
	while (!myq.empty())
	{
		int x = myq.front().first;
		int y = myq.front().second;
		if (x == ex - 1 && y == ey - 1)
		{
			cout << visitied[x][y]<<"\n";
			exit(0);
		}
		myq.pop();
		for (int i = 0; i < 4; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				int nx = x + (dx[i] * j);
				int ny = y + (dy[i] * j);
				//cout << nx << " " << ny << "\n";
				if (nx < 0 || ny < 0 || nx >=n || ny >=m || arr[nx][ny] == '#')
					break;
				if (visitied[nx][ny] == 0)
				{
					myq.push({ nx,ny });
					visitied[nx][ny] = visitied[x][y] + 1;
				}
				else if (visitied[nx][ny]<visitied[x][y]+1)
						break;
				else if (visitied[nx][ny]==visitied[x][y] + 1)
					continue;
			}
		}
	}
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << visitied[i][j] << " ";
		}
		cout << "\n";
	}*/
	cout << -1;
	return 0;
}