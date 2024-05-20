#include <iostream>
#include <queue>
#include <tuple>
#include<string>
#include<queue>
#include<climits>
#include<string>
int n, m, x;

using namespace std;

typedef pair<int, int> Node;
vector < vector < Node>>arr;
vector<bool>visitied;
vector<int>result;
vector<int>reResult;


void dixtra(int start)
{
	fill(visitied.begin(), visitied.end(), false);
	fill(result.begin(), result.end(), INT_MAX);
	priority_queue<Node, vector<Node>, greater<Node>>myQue;
	result[start] = 0;
	myQue.push(Node(0, start));
	while (!myQue.empty())
	{
		Node Now=myQue.top();
		int Now_Node = Now.second;
		myQue.pop();
		if (visitied[Now_Node])
		{
			continue;
		}
		visitied[Now_Node] = true;

		for (Node i : arr[Now_Node])
		{
			int next_val = i.second;
			int next_Node = i.first;
			if (result[next_Node] > next_val + result[Now_Node])
			{
				result[next_Node] = next_val + result[Now_Node];
					myQue.push(Node(result[next_Node], next_Node));
			}
		}
	}
}
int main() {

	cin >> n >> m >> x;
	arr.resize(n + 1);
	visitied.resize(n + 1);
	result.resize(n + 1);
	reResult.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int v, e, w;
		cin >> v >> e >> w;
		arr[v].push_back(Node(e, w));
	}
	for (int i = 1; i <= n; i++)
	{
		dixtra(i);
		reResult[i] += result[x];
		
	}
	dixtra(x);
	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		reResult[i] += result[i];
		if (reResult[i] > max)
		{
			max = reResult[i];
		}
	}
	cout << max;
}