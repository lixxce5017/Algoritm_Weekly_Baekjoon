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
int n;
//조합날릴때 조심
//ssssyyy 가 카운트 될때 다른 경우의 수에서 와서
//카운트 할 수 있는 부분은
//조합+ 임도연파가 4개 이상 되는 순간 가지치기해서 한 번만 정답을 보는것으로 막는다
//특징: 연결되어 있는 곳에서 연결 확인+ y/s 여부 보면 안됨 정답 카운트가 더 됨
//조합 날리는 것은 list에 넣어 날리건 25로 날리건 5/5 이중 포문 얘만 빼고 조합만 되면됨. 


//이중 포문 
//0 0,1 1, 22, 33,44,43, 3,2, 2,1 이런식으로 지극히 적게 경우의 수를 보게 됨
//25:0,1 0, 2, 0,3 ,0,4, 0,5 ,1,0 1,1,1,2 이런식으로 idx로 막아도 더 나머지 연산으로 더 많이 경우를 보게됨
char arr[10][10];
bool visitied[10][10];
bool selected[5][5];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int cnt = 0;
vector<pair<int, int>> Map;
int check(int x, int y)
{
	int count = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
			continue;
		if (selected[nx][ny] == false||visitied[nx][ny]==true)
			continue;
		visitied[nx][ny] = true;
		count += check(nx, ny);
	}	
	return count;
}

void dfs(int depth,int idx,int x,int y,int nocnt)
{
	if (nocnt>3)
		return;
	if (depth == 7)
	{
		memset(visitied, false, sizeof(visitied));
		visitied[x][y] = true;
		
		int count = check(x, y);
		if (count == 7)
			cnt++;
		return;
	}
	for(int i=idx;i<25;i++)
	{ 
		int nx = i / 5;
		int ny = i% 5;
		if (selected[nx][ny] == false)
		{
			int qwer = 0;
			if (arr[nx][ny] == 'Y')
				qwer++;
			selected[nx][ny] = true;
			dfs(depth + 1, i + 1, nx, ny, nocnt+qwer);
			selected[nx][ny] = false;
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> arr[i][j];
			Map.push_back({ i,j });
		}
	}
	dfs(0, 0,0,0,0);
	cout << cnt;
}