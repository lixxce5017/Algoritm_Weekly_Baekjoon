#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
queue<int>que;
int visitied[103] = { 0, };
int map[103];
int m, n;
void bfs() {
    que.push(1);
    visitied[1] = 1;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();

        for (int i = 1; i <= 6; i++)
        {
            int node = i + now;
            node = map[node];
            if (node <= 100 && visitied[node] == -1)
            {
                que.push(node);
                visitied[node] =visitied[now]+1;
            }
        }
    }
    cout << visitied[100]-1;
    return;
}
void input()
{

    cin >> n >> m;
   for (int i = 1; i <= 100; i++)
    {
       visitied[i] = -1;
        map[i] = i;
    }

   for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        map[u] = v;

    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        map[u] = v;
    }
    bfs();
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();

    return 0;
}