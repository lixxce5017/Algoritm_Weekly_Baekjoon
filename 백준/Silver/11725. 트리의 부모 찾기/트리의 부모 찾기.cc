#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int>>Arr;
vector<bool>visitied;
vector<int>result;
void bfs()
{
    queue<int> qqq;
    qqq.push(1);
    visitied[1];
    while (!qqq.empty())
    {
        int now = qqq.front();
        qqq.pop();
        for (int i : Arr[now])
        {
            if (visitied[i]== false)
            {   
                result[i] = now;
                visitied[i] = true;
                qqq.push(i);
            }
        }

    }


}
int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    Arr.resize(n + 1);
    visitied.resize(n + 1, false);
    result.resize(n + 1);

    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        Arr[a].push_back(b);
        Arr[b].push_back(a);
    }
    bfs();
    for (int i = 2; i <= n; i++)
    {
        cout << result[i] << "\n";
    }
  
}
