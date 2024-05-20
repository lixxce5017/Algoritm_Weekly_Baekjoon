#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef pair<int, int> Node;
int arr[101][101];
bool visitied[101][101];
int N;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int max_v;
vector<int>result;
void check(int i, int j,int loop)
{
	queue<Node>q;
	q.push(Node(i, j));
	visitied[i][j] = true;
	while (!q.empty())
	{
		Node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + now.first;
			int ny = dy[i] + now.second;
			if (nx >= 0 && ny >= 0 && nx < N && ny < N)
			{
				if (visitied[nx][ny] == false && arr[nx][ny]>loop)
				{
					visitied[nx][ny] = true;
					q.push(Node(nx, ny));
				}
			}
		}
	}
}
void initail()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visitied[i][j] = false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (i == 0 && j == 0) {
				max_v = arr[i][j];
			}
			if (arr[i][j] > max_v)
			{
				max_v = arr[i][j];
			}
		}
	}
	int loop_value = 0;
	while (loop_value <= max_v)
	{
		initail();
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visitied[i][j]==false&&arr[i][j]> loop_value)
				{
					cnt++;
					check(i, j, loop_value);
				}
			}
		}
		loop_value++;
		result.push_back(cnt);
	}
	cout << *max_element(result.begin(), result.end());

}