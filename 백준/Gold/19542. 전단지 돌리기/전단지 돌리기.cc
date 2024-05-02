#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>


#define MAX 1000001
typedef long long ll;
using namespace std;
int n,start,d;
int ans;
vector<int> arr[100004];
bool visitied[100004];
int dfs(int node)
{
    int mx = 0;
    for (auto i : arr[node])
    {
        if (visitied[i] == false)
        {
            visitied[i] = true;
            int m = dfs(i);
            mx = max(m, mx);
        }
    }
    if (mx >= d)
    {
        ans++;
    }
    return mx+1;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> start >> d;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    visitied[start] = true;
    dfs(start);
    cout << max(0,(ans-1)*2);
    return 0;
}