#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;
int arr[51][51];
bool visitied[51][51];
int n, m;
//북,남,서,동
int dx[4] = { -1,0 , 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int ans = 0;
void dfs(int x, int y, int d)
{
    if (visitied[x][y] == false)
    {
        visitied[x][y] = true;
        ans++;
    }
    bool falg = true;
    for (int i = 0; i < 4; i++)
    {
        //반시계다 주의
        //반시계는 -1에 %4를 하여 -1이 나올 수 있으니 주의가 필요하다.
        int dir = (d - i + 3) % 4;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;
        if (visitied[nx][ny] == true || arr[nx][ny] == 1)
            continue;
        falg = false;
        dfs(nx, ny, dir);
    }
    if (falg)
    {
        if (arr[x - dx[d]][y - dy[d]] == 0)
        {
            dfs(x - dx[d], y - dy[d], d);
        }
        else
        {
            cout << ans << "\n";
            exit(0);
        }
       return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
        cin >> n >> m;
    int sx, sy,q;
    cin >> sx >> sy>>q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
  

    dfs(sx, sy,q);
    cout << ans;
}
