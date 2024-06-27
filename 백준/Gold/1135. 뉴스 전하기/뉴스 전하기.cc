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


int dfs(int node)
{
    //cout << node << " ";
    int cnt =0;
    vector<int> list;
    for (auto i : arr[node])
    {
        list.push_back(dfs(i) + 1);
    }
    sort(list.begin(), list.end(), greater<int>());
    for (int i = 0; i < list.size(); i++)
    {
        list[i] = list[i] + i;
        cnt = max(list[i], cnt);
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    arr.resize(n + 1);
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a == -1)
        {
            start = i;
        }
        else
        {
            arr[a].push_back(i);
        }
    }

    cout << dfs(start);

}