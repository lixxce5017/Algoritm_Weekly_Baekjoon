#include<iostream>
#include<cmath>
#include<vector>
#include<climits>

using namespace std;
int n;
int house[1004][3];
int memo[1004][3][3] = { 0, };



int TopDown(int here, int color,int start)
{
	if (here == n)
	{
		return 0;
	}
	if (memo[here][color][start] > 0&& memo[here][color][start]!= INT_MAX)
	{
		
		return memo[here][color][start];
	}
	for (int i = 0; i < 3; i++)
	{
		if (i == color)
			continue;
		else if (here == n - 2&& i == start)
			continue;
		memo[here][color][start] = min(memo[here][color][start],
			TopDown(here + 1, i, start)+house[here][color]);
	}
	//cout<< memo[here][color][start] << " ";
	return memo[here][color][start];
	
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> house[i][0] >> house[i][1] >> house[i][2];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				memo[i][j][k] = INT_MAX;
			}
		}
	}

	
	int ans = INT_MAX;
	for (int i = 0; i < 3; i++)
	{
		ans = min(ans, TopDown(0, i, i));
	}
	
	cout << ans;
}
