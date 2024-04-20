#include <iostream>
#include <queue>
#include <tuple>
#include<string>
#include<queue>
#include<climits>
#include<string>
int n, m;
#define INF 987654321
using namespace std;
typedef pair<int, int> Node;
vector < vector < Node>>arr;
vector<bool>visitied;
vector<int>result;
int a, b;


void dixtra(int start)
{
	fill(result.begin(), result.end(), INT_MAX);
	priority_queue<Node, vector<Node>, greater<Node>>myQue;
	result[start] = 0;
	myQue.push(Node(0, start));
	while (!myQue.empty())
	{
		Node Now = myQue.top();
		int Now_Node = Now.second;
		myQue.pop();
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

	cin >> n >> m;
	arr.resize(n + 1);
	visitied.resize(n + 1);
	result.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int v, e, w;
		cin >> v >> e >> w;
		arr[v].push_back(Node(e, w));
		arr[e].push_back(Node(v, w));
	}

	cin >> a >> b;
	dixtra(a);
	long long int a_to_n = result[n];
	long long int a_to_b = result[b];
	long long int a_to_1 = result[1];
	dixtra(b);
	long long int b_to_n=result[n];
	long long int b_to_a=result[a];
	long long int b_to_1=result[1];
	long long int answer = a_to_1 + a_to_b + b_to_n;
	long long int answer2 = b_to_1 + b_to_a + a_to_n;
	long long ans = answer > answer2 ? answer2 : answer;
	if (ans >= INF)
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}
	return 0;
}