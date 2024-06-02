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
int map[51][51];
int n;
int k;
vector<pair<int, int>>chikin;
vector<pair<int, int>>home;
vector<pair<int, int>>V;
bool Select[13];
int chik_Size = 0;
int ret = INT_MAX;
/// <summary>
/// 대피소 후기 
/// 실버 1정도 골5 정도? 치킨배달 완전하위호완 
/// </summary>
/// <returns></returns>
int disten_Detect()
{
	int distic = 0;
	for (int i = 0; i < chikin.size(); i++)
	{

		int x = chikin[i].first;
		int y = chikin[i].second;
		int d = INT_MAX;

		for (int j = 0; j < V.size(); j++)
		{
			int xx = V[j].first;
			int yy = V[j].second;


			int dist = abs(xx - x) + abs(yy - y);

			d = min(dist, d);
			//cout << d << " ";
		}
		distic = max(d, distic);
	}
	return distic;
}

void dfs(int idx, int cnt)
{
	if (cnt == k)
	{
		ret = min(disten_Detect(), ret);
		return;
	}
	for (int i = idx; i < n; i++)
	{
			V.push_back(make_pair(chikin[i].first, chikin[i].second));
			dfs(i+1, cnt + 1);
			V.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	//2가 치킨집 //1이 집


	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int y, x;
		cin >> y >> x;
		chik_Size++;
		chikin.push_back(make_pair(y, x));
	}


	dfs(0, 0);
	if (ret == INT_MAX)
	{
		cout << 0;
	}
	else
	{
		cout << ret;
	}
	

}