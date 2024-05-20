#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

int n,m;
int arr[1003][1003];
int copyMap[1003][1003];
bool visitied[1003][1003];
int cnt = 1;
vector<pair<int,int>>res;
vector<pair<int, int>>go;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int tmp = 0;
void bfs(int x, int y)
{
	tmp = 1;
	res.clear();
	//큐 초기화 잊지말자
	queue<pair<int, int>>que;
	que.push(make_pair(x, y));
	visitied[x][y] = true;
	while (!que.empty())
	{
	
		int nx = que.front().first;
		int ny = que.front().second;
		que.pop();
		for (int i = 0;i < 4;i++)
		{
			int nex = nx + dx[i];
			int ney = ny + dy[i];
			if (nex < 0 || ney < 0 || nex >= n || ney >= m)
			{
				continue;
			}

			if (arr[nex][ney] == 0 && visitied[nex][ney] == false)
			{
				tmp++;
				visitied[nex][ney] = true;
				que.push(make_pair(nex, ney));
			}
			else if (arr[nex][ney] != 0 && visitied[nex][ney] == false)
			{
				visitied[nex][ney] = true;
				res.push_back(make_pair(nex, ney));
			}
		}
	}
	for (int i = 0;i < res.size();i++)
	{
		arr[res[i].first][res[i].second] += tmp;;
		visitied[res[i].first][res[i].second] = false;
	}
}



int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cout.tie(NULL);

	cin >> n>>m;
	for (int i = 0;i < n;i++)
	{
		string s; 
		cin >> s;
		for (int j = 0;j < m;j++)
		{
			arr[i][j]= s[j]-'0';
			if (arr[i][j] == 0)
			{
				go.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 0;i < go.size();i++)
	{
		if (visitied[go[i].first][go[i].second] == false)
		{
			bfs(go[i].first, go[i].second);
		}
	}


	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cout << arr[i][j]%10;
		}
		cout << "\n";
	}
	


}