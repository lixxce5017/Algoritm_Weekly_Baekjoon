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
int n, m;
char Map[11][11];
bool visitied[11][11][11][11];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int res = INT_MAX;	
struct marble {
	int rx, ry, bx, by, count;
};
queue<marble>myq;
//!= '#' 로 해야하는 이유 .일때만 간다면 0에 도달해서 검사를 못함.
//4차원 비지티드로 가야하는 이유
// 빨 블루가 동시에 움직이기 때문에 4차원으로 한방에 처리해야함
//동시에 빠지는 것도 처리해야함
//숫자 0이 아닌 대문자 영어 o임
int simutlaion(int& x, int& y, int d1, int d2)
{
	int m_count = 0;
	while (Map[x + d1][y + d2] != '#' && Map[x][y] != 'O')
	{
		x=x + d1; y=y + d2;
		m_count++;
	}
	return m_count;
}

void bfs(int srx, int sry, int sbx, int sby)
{
	myq.push({ srx,sry,sbx,sby,0 });
	visitied[srx][sry][sbx][sby] = true;


	while (!myq.empty())
	{
		marble now = myq.front();
		myq.pop();
		int x1 = now.rx;
		int y2 = now.ry;
		int x3 = now.bx;
		int b4 = now.by;
		int count = now.count;
		if (count >= 10)
			continue;
		for (int i = 0; i < 4; i++)
		{
			int rx = x1;
			int ry = y2;
			int bx = x3;
			int by = b4;
			int rmc=simutlaion(rx, ry, dx[i], dy[i]);
			int bmc = simutlaion(bx, by, dx[i], dy[i]);
			//먼저 와야지 동시처리에서 스킵하고 넘어갈 수 있음

			if (Map[bx][by] == 'O')
			{
				continue;
			}
			if (Map[rx][ry] == 'O')
			{
				res = min(res, count+1);
				continue;
			}
			//파란공이 빠짐 컨티뉴
			//서로 붙어있는 경우 처리
			if (rx == bx && ry == by)
			{
				if (rmc <bmc)
				{
					bx -= dx[i];
					by -= dy[i];
				}
				else
				{
					rx -= dx[i];
					ry -= dy[i];
				}
			}
			if (visitied[rx][ry][bx][by] == true)
				continue;
			visitied[rx][ry][bx][by] = true;
			myq.push({ rx,ry,bx,by,count + 1 });
		}
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int r1=0, r2=0, b1=0, b2=0;
	cin >> n>>m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == 'B')
			{
				b1 = i; b2 = j;
			}
			else if (Map[i][j] == 'R')
			{
				r1 = i; r2 = j;
			}
		}
	}
	bfs(r1, r2, b1, b2);
	if (res==11||res==INT_MAX)
		cout << -1;
	else
		cout << res;

}