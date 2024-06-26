#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<queue>
using namespace std;
int arr[103];
int n;
int mul[4];
int maxx = -INT_MAX;
int minn = INT_MAX;
void dfs(int idx, int res)
{
    if (idx == n)
    {
        if (res > maxx)
        {
            maxx = res;
        }
        if (res < minn)
        {
            minn = res;
        }
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (mul[i] > 0)
        {
            mul[i]--;
            if (i == 0)
            {
                dfs(idx + 1, res + arr[idx]);
            }
            else if (i == 1)
            {
                dfs(idx + 1, res - arr[idx]);
            }
            else if (i == 2)
            {
                dfs(idx + 1, res * arr[idx]);
            }
            else
            {
                dfs(idx + 1, res / arr[idx]);
            }
            mul[i]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> mul[i];
    }
   
    dfs(1, arr[0]);
    cout << maxx << "\n" << minn;
     return 0;

}