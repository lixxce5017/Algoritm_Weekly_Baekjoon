#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<queue>
#include <climits>
#include<tuple>
#include<limits.h>
#include<tuple>
using namespace std;
typedef tuple<int, int, int> t;
int arr[103][103];
int visitied[103][103][3];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			arr[i][j] = s[j]-'0';
		}
	}
	queue<t> myq;
	int x1, x2, y1, y2, z1, z2;
	cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
	myq.push(t(x1-1, x2-1,0));
	myq.push(t(y1-1, y2-1,1));
	myq.push(t(z1-1, z2-1,2));
	visitied[x1-1][x2-1][0] = 1;
	visitied[y1-1][y2-1][1] = 1;
	visitied[z1-1][z2-1][2] = 1;

	//visitied[x1-1][x2-1][0] = true;
	//visitied[y1-1][y2-1][0] = true;
	//visitied[z1-1][z2-1][0] = true;
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	bool flag = true;
	int cnt = 0;
	int val = 0;
	while (!myq.empty())

	{
		t ne = myq.front();
		int nx = get<0>(ne);
		int ny = get<1>(ne);
		int num= get<2>(ne);
		//cout<< nx << " " << ny<<" "<<num<<" "<< visitied[nx][ny][0] << "\n";
		myq.pop();
		for (int i = 0; i < 4; i++)
		{
			int nex = nx + dx[i];
			int ney = ny + dy[i];
			if (nex < 0 || ney <0  || ney>=m || nex>=n)
			{
				continue;
			}
			if (arr[nex][ney] != 0 || visitied[nex][ney][num] != 0)
				continue;
			visitied[nex][ney][num]=visitied[nx][ny][num]+1;
			myq.push(t(nex, ney, num));

		}
	}
	int ans = INT_MAX;
	int cc = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			bool falg = true;
			int val = -1;
			//cout << visitied[i][j][0] << " " << visitied[i][j][1] << " " << visitied[i][j][2] << " ";
			for (int k = 0; k < 3; k++)
			{
				if (visitied[i][j][k] >val)
				{
					val = max(val, visitied[i][j][k]);
				}
				else if(visitied[i][j][k]==0)
				{

					falg = false;
				}
			}
			//cout << "\n";
			if (falg == true&&val<ans)
			{
				cc = 1;
				//cout << val<<" ";
				ans = min(val, ans);
			}
			else if (ans == val&&falg==true)
			{
				cc++;
			}
			//cout << "\n";
		}
	}
	if (ans == INT_MAX)
	{
		cout << -1;
	}
	else
	{
		cout << ans-1<< "\n" << cc;
	}
}

