#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;
int n;
int arr[11][11];
int l[20];
int r[20];
int maxx;
int ans[2];
void dfs(int row,int col,int count,int color)
{
    if (col >= n)
    {
        row++;
        if (col % 2 == 0)
            col = 1;
        else
            col = 0;
    }
    if (row >= n)
    {
        ans[color] = max(ans[color], count);
        return;
    }
    if (arr[row][col] && !l[col - row + n - 1] && !r[row + col])
    {
        l[col - row + n - 1] = 1;
        r[col + row] = 1;
        dfs(row, col + 2, count + 1, color);
        l[col - row + n - 1] = 0;
        r[row + col] = 0;

    }
    dfs(row, col + 2, count, color);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);



    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    dfs(0, 0, 0, 0);
    dfs(0, 1, 0, 1);
    cout << ans[0]+ans[1];
     return 0;

}