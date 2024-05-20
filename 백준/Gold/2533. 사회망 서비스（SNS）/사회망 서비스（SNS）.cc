#include <iostream>
#include <queue>
#include <tuple>
#include<string>
#include<queue>
#include<climits>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> arr;
vector<int>Val;
vector<bool>visitied;
int n;
int dp[1000000][2];

void bfs(int x)
{//1이 우수마을 
//0가 는 일반 마을
	visitied[x] = true;
	dp[x][1] = 1;
	for (auto i : arr[x])
	{
		if (visitied[i] == false)
		{
			bfs(i);
			dp[x][1] += min(dp[i][1] ,dp[i][0]);
			dp[x][0] = dp[i][1]+dp[x][0];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	Val.resize(n + 1);
	arr.resize(n + 1);
	visitied.resize(n + 1);

	for (int i = 1; i <n; i++)
	{
		int a, b;
		cin >> a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
		
	}
	bfs(1);

	cout << min(dp[1][0], dp[1][1]);

	return 0;
}