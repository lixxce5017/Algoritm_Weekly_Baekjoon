#include <iostream>
#include <vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include<climits>
#include<queue>
int arr[21][21];
bool visitied[21];
using namespace std;
int n;
int minnn = INT_MAX;
int teamNum = 0;

void dfs(int num, int team)
{
	if (team>=2)
	{
		int start = 0;
		int link = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visitied[i] == true && visitied[j] == true)
				{
					start += arr[i][j];
				}
				else if (visitied[i] == false && visitied[j] == false)
				{
					link += arr[i][j];
				}
			}
		}
		int tmp = abs(start - link);
		minnn = min(minnn, tmp);
		
	}
	for (int i = num; i < n; i++)
	{
		visitied[i] = true;
		dfs(i + 1, team + 1);
		visitied[i] = false;
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	teamNum = n / 2;
	dfs(0, 0);
	cout << minnn;
}


