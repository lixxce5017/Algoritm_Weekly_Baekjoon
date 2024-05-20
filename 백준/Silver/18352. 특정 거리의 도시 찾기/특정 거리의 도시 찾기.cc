#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<sstream>
#include<tuple>
#include<queue>
using namespace std;
static vector<vector<int>> A;
static vector<int> answer;
static vector<int> visitied;

void BFS(int node);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long N, M, K, X;
	cin >> N >> M >> K >> X;
	A.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		int S, E;
		cin >> S >> E;
		A[S].push_back(E);
	}
	visitied.resize(N + 1,-1);
	BFS(X);

	for (int i = 1; i <= N; i++)
	{
		if (visitied[i] == K)
		{
			answer.push_back(i);
		}
	}
	if (answer.empty())
	{
		cout << -1 << "\n";
	}
	else
	{
			for (int temp : answer)
			{
				cout << temp << "\n";
		}
	}
}


void BFS(int node)
{
	queue<int>queue;
	queue.push(node);
	visitied[node]=0;
	while (!queue.empty())
	{
		int now_node = queue.front();
		queue.pop();
		for (int i : A[now_node])
		{
			if (visitied[i] == -1)
			{
				visitied[i] = visitied[now_node] + 1;
				queue.push(i);
			}
		}
	}
	
}
                                                            