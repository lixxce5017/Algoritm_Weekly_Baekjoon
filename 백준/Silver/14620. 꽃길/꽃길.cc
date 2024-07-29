#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include<cstring>
#include<limits.h>
int n;
int arr[11][11];
int dead_jude[11][11];
using namespace std;
vector<pair<int, int>> flwoer;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int x1, x2, x3;
int yy, y2, y3;
bool falg = true;
int check(int x, int y)
{
    int ret_val = arr[x][y];
    dead_jude[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
        {
            falg = false;
            return 0;
        }
        if (dead_jude[nx][ny] == 1)
        {
            falg = false;
            return 0;
        }
        ret_val += arr[nx][ny];
        dead_jude[nx][ny] = 1;
    }
   // cout << ret_val << "\n";
    return ret_val;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            flwoer.push_back({ i,j });
        }
    }
    int range_f = flwoer.size();
    int ans = INT_MAX;
    for (int i = 0; i < range_f -2; i++)
    {
        for (int j = i+1; j < range_f -1; j++)
        {
            for (int k = j+1; k < range_f; k++)
            {
                falg = true;
                int tmp = 0;
                memset(dead_jude, 0, sizeof(dead_jude));
                 x1 = flwoer[i].first;
                 yy = flwoer[i].second;
                 x2 = flwoer[j].first;
                 y2 = flwoer[j].second;
                 x3 = flwoer[k].first;
                 y3 = flwoer[k].second;
                 //cout << x1 << " " << yy << " " << x2 << " " << y2 << " " << x3 << " " << y3 << "\n";
                 tmp+=check(x1, yy);
                 tmp+=check(x2, y2);
                 tmp+=check(x3, y3);
                 if (falg == false)
                     continue;
                // cout << tmp << "\n";
                 ans = min(tmp, ans); 
            }
        }
    }
    cout << ans;
}