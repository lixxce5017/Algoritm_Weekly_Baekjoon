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
bool res = false;	
/* 4차원 가야하는 이유 반례
입력
10 10
##########
#........#
#.....B..#
#..#.R.#.#
#...#....#
#........#
#....#...#
#........#
#....O#..#
##########

출력
0

정답
1

비고
1) 아래쪽으로 기울이기
2) 오른쪽으로 기울이기
3) 아래쪽으로 기울이기
4) 왼쪽으로 기울이기
5) 아래쪽으로 기울이기
6) 오른쪽으로 기울이기*/
struct marble {
	int rx, ry, bx, by, count;
};
queue<marble>myq;
void simutlaion(int& x, int& y, int d1, int d2,int &c)
{
	while (Map[x][y] != 'O'&&Map[x+d1][y+d2]!='#')
	{
		//cout << x << " " << y << "\n";
		x += d1;
		y += d2;
		c++;
	}
}

void bfs(int srx, int sry, int sbx, int sby)
{
	myq.push({ srx,sry,sbx,sby,0 });
	visitied[srx][sry][sbx][sby] = true;
	while (!myq.empty())
	{
		marble now = myq.front();
		int rx = now.rx;
		int ry = now.ry;
		int bx = now.bx;
		int by = now.by;

		int count = now.count;
		myq.pop();
		if (count >=10)
			return;
		for (int i = 0; i < 4; i++)
		{
			int rc = 0, bc = 0;
			int rxn = rx;
			int ryn = ry;
			int bxn = bx;
			int byn = by;
			simutlaion(rxn, ryn, dx[i], dy[i],rc);
			simutlaion(bxn, byn, dx[i], dy[i],bc);
			if (Map[bxn][byn] == 'O')
			{
				//cout << 0;
				//exit(0);
				continue;
			}
			if (Map[rxn][ryn] == 'O')
			{
				cout<<1;
				exit(0);
			}
			if (bxn == rxn && byn == ryn)
			{
				if (rc < bc)
				{
					bxn -= dx[i];
					byn -= dy[i];
				}
				else
				{
					rxn -= dx[i];
					ryn -= dy[i];
				}
			}
			if (visitied[rxn][ryn][bxn][byn] == true)
				continue;
			visitied[rxn][ryn][bxn][byn] = true;
			myq.push({ rxn,ryn,bxn,byn,count + 1 });
		}
	}
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
	cout << 0;

}