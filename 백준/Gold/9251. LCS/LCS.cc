#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
using namespace std;

int N,m;


int dp[1003][1003] = { 0, };
int main()
{
	string a, b;
	cin >> a>>b;
	int aLen = a.size();
	int bLen = b.size();
	int MaxN = 0;
	for (int i = 1; i <= aLen; i++)
	{
		for (int j = 1; j <= bLen; j++)
		{
			if (a[i-1] == b[j-1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			MaxN = max(MaxN, dp[i][j]);
		}
	}
	cout << MaxN;

}