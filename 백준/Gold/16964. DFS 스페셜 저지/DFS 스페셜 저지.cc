#include <algorithm>
#include <vector>
#include<cstring>
#include <iostream>
typedef long long ll;
using namespace std;
vector<vector<int>> arr;
//dfs는 기본적으로 아무대나 가도된다.
//그렇다면 그 아무대나 가는것에 대해서 기준을 정렬로 잡아주고
//가는곳을 다 list에 넣고 문제에서 원하는 순서와 비교하는 것이다.
//order[a]=i란 a번째 정점은 i번째로 가야한다 
//path[i]=a dfs에서 i번째 방문은 a번째 노드이다.

bool chk[100003];
int order[100003];
int cnt = 0;
bool cmp(int a, int b)
{
    if (order[a] <order[b])
    {
        return true;
    }
    else
        return false;
}
vector<int> list;
vector<int> path;
void dfs(int node)
{;
    chk[node] = true;
    list.push_back(node);
     for (auto i : arr[node])
      {
            if (chk[i] == false)
                dfs(i);
      }
  
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    arr.resize(n + 1);
    path.resize(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    list.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        
        int a;
        cin >> a;
        order[a] = i;
        path[i] = a;
    }
    for (int i = 1; i <= n; i++)
    {
        sort(arr[i].begin(), arr[i].end(),cmp);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        if (path[i] != list[i])
        {
          
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}