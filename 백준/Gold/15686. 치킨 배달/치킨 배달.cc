#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<queue>
#include <climits>
#include<tuple>
#include<limits.h>
#include <cmath>
using namespace std;
struct CCTV {
	int type, y, x;
};
int n, m;
int map[51][51];
vector<pair<int, int>>chikin;
vector<pair<int, int>>home;
vector<pair<int, int>>V;
bool Select[13];
int chik_Size = 0;
int ret = 99999999;
int disten_Detect()
{
	int distic = 0;
	for (int i = 0; i < home.size(); i++)
	{
		
		int x = home[i].first;
		int y = home[i].second;
		int d = 99999999;
		for (int j = 0; j < V.size(); j++)
		{
			int xx = V[j].first;
			int yy = V[j].second;
			int dist = abs(xx - x) + abs(yy - y);

			d = min(d, dist);
		}
		distic += d;
	}
	return distic;
}

void dfs(int idx,int cnt)
{
	if (cnt == m)
	{
		ret=min(disten_Detect(), ret);
	}
	for (int i = idx; i < chik_Size; i++)
	{
		if (Select[i] == false)
		{
			Select[i] = true;
			V.push_back(make_pair(chikin[i].first, chikin[i].second));
			dfs(i, cnt + 1);
			Select[i] = false;
			V.pop_back();
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	cin >> n >> m;
	//2가 치킨집 //1이 집
	
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> map[y][x];
			if (map[y][x] == 2)
			{
				chik_Size++;
				chikin.push_back(make_pair(y, x));
			}
			else if (map[y][x] == 1)
			{
				home.push_back(make_pair(y, x));
			}
		}
	}
	dfs(0, 0);
	cout << ret;
	
}