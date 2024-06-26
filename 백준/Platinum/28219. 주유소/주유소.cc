#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<int>> arr;
bool visitied[200004];
int dp[200004];
int n, k;
int ret = 0;

void dfs(int cur) {
    int cnt = 0;
    visitied[cur] = true;
    vector<int> res;
    for (auto i : arr[cur])
    {
        if (visitied[i] == false)
        {
            dfs(i);
            dp[cur] = max(dp[cur], dp[i] + 1);
            res.push_back(dp[i]+1);
        }
    }
    sort(res.rbegin(), res.rend());
    if (res.size() == 1)
        cnt = max(cnt, res[0]);
    else if (res.size() > 1)
        cnt = max(cnt, res[0] + res[1]);
    if (cnt >= k)
    {
        ret++;
        dp[cur]=-1;
    }
}

int main() {

    cin >> n >> k;
    arr.resize(200004);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    dfs(1);
    cout << ret;
}