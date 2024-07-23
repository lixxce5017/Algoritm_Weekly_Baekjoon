#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int arr[16];
int cnt = 0;
void dfs(int val);
bool check(int node);

int main() {
    cin >> n;
 
    dfs(0);
    cout << cnt;
    return 0;
}

void dfs(int cur) {

    if (cur == n)
    {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        arr[cur] = i;
        if (check(cur)==true)
        {
            dfs(cur + 1);
        }
    }

}

bool check(int node)
{
    for (int i = 0; i < node; i++)
    {
        if (arr[node] == arr[i]||abs(arr[node]-arr[i])==node-i)
        {
            return false;
        }
    }
   
    return true;
}