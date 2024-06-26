#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<int>> arr;
vector<vector<int>> tree_arr;
bool visitied[200004];
int n, k;
int ret = 0;
void tree(int node)
{
    visitied[node] = true;
    for (auto i : arr[node])
    {
        if (visitied[i] == false)
        {
            tree_arr[node].push_back(i);
            tree(i);
        }
    }
}
// 단방향 그래프인 트리라  필요없다 visitied
int dfs(int cur) {
    int cnt = 0;
    vector<int> res;
    //cout << cur << " ";
    for (auto i : tree_arr[cur])
    {
        int temp = dfs(i);
        res.push_back(temp);
    }
    sort(res.begin(), res.end(), greater<int>());
    if (res.size() > 1)
        cnt = max(cnt, res[0] + 1 + res[1] + 1);
    else if (res.size() == 1)
        cnt = max(cnt, res[0] + 1);
    if (cnt >= k)
    {
        ret++;
        cnt = -1;
    }
    return cnt;
}

int main() {

    cin >> n >> k;
    arr.resize(n + 1);
    tree_arr.resize(n + 1);
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    visitied[1] = true;
    tree(1);
    dfs(1);
    cout << ret;
}