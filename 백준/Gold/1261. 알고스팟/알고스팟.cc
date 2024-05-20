#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include <climits>
#include<cstring>
#include<tuple>
using namespace std;
vector<int>result;
typedef tuple <int, int,int> node;
int arr[101][101];
int dp[101][101];
bool visitied[101][101] = { false, };
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
#define INF 987654321
int n, m;
void dixtra()
{
	priority_queue<node, vector<node>, greater<node>>myQue;
	dp[0][0] = 0;
	myQue.push(node(0,0,0));
	while (!myQue.empty())
	{
		node Now = myQue.top();
		int now_conut = get<0>(Now);
		int Now_Nodei = get<1>(Now);
		int Now_Nodej = get<2>(Now);
		myQue.pop();
		if (dp[Now_Nodei][Now_Nodej] < now_conut)
			continue;
		for (int i = 0; i < 4; i++)
		{
			int next_count;
			int next_x = dx[i] + Now_Nodei;
			int next_y = dy[i] + Now_Nodej;
			if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n)
			{
			
				if (arr[next_x][next_y] == 0) {
			
					next_count = dp[Now_Nodei][Now_Nodej];
				}
				else {
				
					next_count = dp[Now_Nodei][Now_Nodej] + 1;
				}
				if (dp[next_x][next_y] > next_count) {
					myQue.push(node(next_count,next_x,next_y));
					dp[next_x][next_y] = next_count;
				}
			}
		}
	}
	
	cout << dp[m - 1][n - 1];
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char ch;
			cin >> ch;
			dp[i][j] = INF;
			arr[i][j] = ch- '0';
		}
	}

	dixtra();
	return 0;

}