#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;
int arr[1003][1003];
bool visitied[1003][1003];
int n,m, k;
//위, 아래,왼쪽,오른쪽
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<int>dir;

void dfs(int x, int y,int d)
{
    visitied[x][y] = true;
    //cout << x << " " << y << "\n";
    int xx = x + dx[dir[d]];
    int yy = y + dy[dir[d]];
    if (arr[xx][yy] != 1&&xx<n&&yy<m&&xx>=0&&yy>=0&& visitied[xx][yy] == false)
    {
        dfs(xx, yy, d);
    }
    else
    {
        int falg = false;
        for (int i=0;i<4;i++)
        {
            int dd= (d + i) % 4;
            int nx = x +dx[dir[dd]];
            int ny = y + dy[dir[dd]];
            if (nx >=n|| ny >=m|| 0 > nx || 0>ny)
                continue;
            if (arr[nx][ny] == 1||visitied[nx][ny]==true)
                continue;
            falg = true;
            dfs(nx, ny, dd);
        }
        if (falg == false)
        {
            cout << x << " " << y<<"\n";
            exit(0);
            return;
        }
    }
 
 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }
    int sx, sy;
    cin >> sx >> sy;
    for (int i = 0; i < 4; i++)
    {
        int a;
        cin >> a;
        dir.push_back(a - 1);
    }
    dfs(sx, sy,0);

}
