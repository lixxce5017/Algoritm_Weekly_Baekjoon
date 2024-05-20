#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include <climits>
using namespace std;
typedef pair<int, int> Node;
vector<int>result;
vector<vector<Node>>arr;
vector<bool>visitied;
int n, m, start;
void dixtra(int start)
{
	fill(visitied.begin(), visitied.end(), false);
	fill(result.begin(), result.end(), INT_MAX);
	priority_queue<Node, vector<Node>, greater<Node>>myQue;
	result[start] = 0;
	int cnt = 0;
	int ans = start;
	myQue.push(Node(0, start));
	while (!myQue.empty())
	{
		Node Now = myQue.top();
		int Now_Node = Now.second;
		myQue.pop();
		if (visitied[Now_Node])
		{
			continue;
		}
		visitied[Now_Node] = true;
		cnt++;
		ans = Now_Node;
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


	
	cout << cnt << " " << result[ans] << "\n";
	return;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
;
			int t;
			cin >> t;
			while (t)
			{
				cin >> n >> m >> start;
				arr.resize(n + 1);
				visitied.resize(n + 1);
				result.resize(n + 1);


				for (int i = 0; i < m; i++)
				{
					int a, b, w;
					cin >> a >> b >> w;
					arr[b].push_back(Node(a, w));
				}

				dixtra(start);
				for (int i = 1; i <= n; i++) {
					arr[i].clear();
				}

				t--;
			}
			return 0;

}