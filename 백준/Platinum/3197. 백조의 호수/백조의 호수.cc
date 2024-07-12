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
//시간 단축 방법 치즈+ 큐 2개를 응용한 시간단축
/*1 7
LXX.XXL
백조도 물위에 있는 것으로 침
ans=2;
물도 백조도 다 넣고 돌리기 시작 얘 때문에 큐 3개 있어야함


int que_size = que2.size();
	while (que_size--)
사이즈만큼 안돌리는 이유가 다 있었음
한 번에 한 친구들씩 갈아내야해서 사이즈만큼 가고 큐에 넣음 계속 갈아버림


que의 의미 :  한쪽 백조에서 부터시작하는 큐
neque 백조에서 시작하여 다음 시간에 진입해 줘야하는 애들을 넣은 큐
que=neque 다음 사이클때 돌아야함

que2 위는 계속 도는 애들이고
처음부터 물과 다른 백조도 다 넣고 실질적으로 한 사이클마다 맵의 얼음을 부수는 시뮬레이션용 큐
*/
int n, m;
int Map[1503][1503];
int delet_Water[1503][1503];
bool visitied_S[1503][1503];
bool visitied_W[1503][1503];
int sx1 = 0;
int sy1 = 0;
int sx2 = 0;
int sy2 = 0;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<int, int>> que;
queue<pair<int, int>> que2;
queue<pair<int, int>> neque;
bool falg = false;
void swanBFS(int x, int y,int x2,int y2)
{
	//cout << "start\n";
	while (!que.empty())
	{
		int xx = que.front().first;
		int yy = que.front().second;
		//cout << xx << " "<<yy << " "<<"\n";
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (nx == x2 && ny == y2&&visitied_S[nx][ny]==false)
			{
				falg = true;
				return;
			}
			if (visitied_S[nx][ny] == true)
				continue;
			if (Map[nx][ny] == 1)
			{
				neque.push({ nx, ny });
				visitied_S[nx][ny] = true;
			}
			if (Map[nx][ny] == 0)
			{
				visitied_S[nx][ny] = true;
				que.push({ nx,ny});
			}
			
		}
	}
	que = neque;
}
void waterBFS()
{

	int que_size = que2.size();
	while (que_size--)
	{
		int xx = que2.front().first;
		int yy = que2.front().second;

		//cout << xx << " " << yy << "\n";
		que2.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (Map[nx][ny] == 1)
			{
				Map[nx][ny] = 0;
				que2.push({ nx,ny });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int sc = 0;
	cin >> n>>m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			if (s[j] == 'X')
				Map[i][j] = 1;
			else if (s[j] == 'L')
			{
				Map[i][j] = 0;
				if (sc == 0)
				{
					sx1 = i; sy1 = j;
					sc++;
				}
				else if (sc == 1)
				{
					sx2 = i; sy2 = j;
				}
			}
			else
			{
				que2.push({ i,j });
				Map[i][j] = 0;
			}
		}
	}
	
	int year = 0;
	que.push({ sx1,sy1 });
	que2.push({ sx2,sy2 });
	visitied_S[sx1][sy1] = true;
	//visitied_S[sx2][sy2] = true;

	while (1)
	{
		swanBFS(sx1, sy1, sx2, sy2);
		if (falg == true)
			break;
		year++;
		waterBFS();
		//cout << year << " ";
	}
	cout << year;
}