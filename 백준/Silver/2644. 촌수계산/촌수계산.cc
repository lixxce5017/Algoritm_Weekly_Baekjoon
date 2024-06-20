#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool visited[1010] = { 0, };
int ans = 0;
vector<vector<int>> graph;


void dfs(int num, int num2, int cnt)
{
    visited[num] = true;

    if (num == num2)
    {
        ans = cnt;
        cout << ans;
        exit(0);
    }
    for (int i = 0; i < graph[num].size(); i++)
    {
        int next_node = graph[num][i];
        if (visited[next_node] == false)
        {
            dfs(next_node, num2, cnt + 1);
        }
    }
}

int main()
{
    int p1, p2, node, edge, a, b;

    cin >> node;

    cin >> p1 >> p2;

    cin >> edge;

    graph.resize(node + 1);

    for (int i = 0; i < edge; i++)
    {
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(p1, p2, 0);

    cout << "-1";
}