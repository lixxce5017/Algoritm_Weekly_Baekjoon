#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
using namespace std;
typedef pair<int, int> edge;
vector<vector<edge>> arr;
vector<bool> visitied;
vector<int>d_distance;


void bfs(int idx)
{
	queue<int>myque;
	myque.push(idx);
	visitied[idx] = true;

	while (!myque.empty())
	{
		int temp = myque.front();
		myque.pop();
		for (edge i : arr[temp])
		{
			if (!visitied[i.first])
			{
				visitied[i.first] = true;
				myque.push(i.first);
				d_distance[i.first] = d_distance[temp] + i.second;
			}
		}
	}
	


}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	arr.resize(n+1);
	for (int i = 0; i < n-1; i++)
	{
		int parent, child, weight;
		cin >> parent >>child >> weight;
		arr[parent].push_back(edge(child, weight));
		arr[child].push_back(edge(parent, weight));


	}
	d_distance = vector <int>(n+1 , 0);
	visitied = vector < bool>(n +1, false);
	
	bfs(1);
	int max;
	max = 1;
		
	for (int i = 2; i <= n; i++)
	{
			if (d_distance[max] < d_distance[i])
			{
				max = i;
			}
	}
	fill(d_distance.begin(), d_distance.end(), 0);
	fill(visitied.begin(), visitied.end(), false);

	bfs(max);
	sort(d_distance.begin(), d_distance.end());
	cout << d_distance[n] << "\n";
}