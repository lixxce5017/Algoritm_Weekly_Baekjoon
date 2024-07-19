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
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<int>ans;
stack<pair<int,int>> lazer;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	bool falg = false;
	for (int i = 1; i <= n; i++)
	{
		//cout << i << " ";
		int tmep;
		cin >> tmep;
		while (!lazer.empty())
		{
			if (lazer.top().first > tmep)
			{
				falg = true;
				ans.push_back(lazer.top().second);
				break;
			}
			lazer.pop();
		}
		if (lazer.empty())
		{
			ans.push_back(0);
		}
		lazer.push({ tmep,i });
	}
	if (falg)
	{
		for (int i =0; i <ans.size(); i++)
		{
			cout << ans[i]<<" ";
		}
	}
	else
	{
		cout << 0;
	}

}