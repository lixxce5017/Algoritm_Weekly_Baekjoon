#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<queue>
#include<stack>
#include<tuple>
#include<limits.h>
using namespace std;
vector<vector<int>> arr;
vector<int> parent;
vector<bool>visitied;

void dfs(int n)
{
    visitied[n] = true;
    for (auto i : arr[n])
    {
        if (visitied[i] == false)
        {
            parent[i] = n;
             dfs(i);
        }
    }

}
int main(void) {
  
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n;
    arr.resize(n + 1);

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    visitied.resize(n + 1);
    parent.resize(n + 1);
    dfs(1);
    for (int i = 2; i <= n; i++)
    {
        cout << parent[i] << "\n";
    }
   
    return 0;
}

