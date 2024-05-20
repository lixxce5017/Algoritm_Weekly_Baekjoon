#include <iostream>
#include <algorithm>
#include <vector>
#include<stdio.h>
#include<queue>
#include<cstring>
#include<cstdlib>
using namespace std;
int arr[103][103];
bool visitied[103][103];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int cnt = 0;
int n, m, k;
void dfs(int x, int y)
{
   
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < n && ny < m)
        {
            if (arr[nx][ny] == 0&&visitied[nx][ny]==false)
            {
                visitied[nx][ny] = true;
                cnt++;
                dfs(nx, ny);
               
            }
        }

    }
   
}
int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   
   
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y, x2, y2;
        cin >> x >> y >> x2 >> y2;
        for (int i = y; i < y2; i++)
        {
            for (int j = x; j < x2; j++)
            {
                if (arr[i][j] == -1)
                    continue;
                arr[i][j] = -1;
            }
        }
    }
  
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visitied[i][j] == false && arr[i][j]==0)
            {
                cnt = 1;
                visitied[i][j] = true;
                dfs(i, j);
                res.push_back(cnt);
            }
        }
    }
  
    sort(res.begin(), res.end());
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}


