#include <iostream>
#include <vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include <cstring>
#include<climits>
#include<queue>
#include<tuple>
int arr[21][21];
//가장 위쪽
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
bool visitied[21][21] = { false, };
using namespace std;
typedef tuple<int, int, int> t;
int n, m;
priority_queue < t, vector<t>, greater<t>> myq;

int bfs(int s1, int s2)
{//우선순위 큐 1,거리순 2 세로 기준 3가로 기준
	myq.push(t(0, s1, s2));
	visitied[s1][s2] = true;
	int shark_size = 2;
	int shark_pery = 0;
	int res = 0;
	while (!myq.empty())
	{
		t now = myq.top();
		int dis = get<0>(now);
		int x = get<1>(now);
		int y = get<2>(now);
		myq.pop();
		//cout << "d";
		if (arr[x][y] < shark_size && arr[x][y]>0)
		{
			shark_pery += 1;
			res = dis;
			//dis = 0;
			//cout << res << "\n";
			if (shark_pery == shark_size)
			{
				shark_size += 1;
				shark_pery = 0;
			}
			while (!myq.empty())
			{
				myq.pop();
			}
			memset(visitied, false, sizeof(visitied));
			arr[x][y] = 0;
			visitied[x][y] = true;
			myq.push(t(0, x, y));
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx >= 0 && ny >= 0 && nx < n && ny < n&& visitied[nx][ny] == false)
			{
				if (arr[nx][ny] <= shark_size)
				{
					visitied[nx][ny] = true;
					myq.push(t(dis + 1, nx, ny));
				}
			}
		}
	}
	cout << res;
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int sx = 0, sy = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 9)
			{
				arr[i][j] = 0;
				sx = i, sy = j;
			}
		}
	}
	bfs(sx, sy);
	return 0;
}