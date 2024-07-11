#include <iostream>

using namespace std;
#include<limits.h>
#include <vector>
#include <algorithm>
#include<queue>
struct gusel {
    int rx, ry, bx, by, cnt;
};
char arr[11][11];
int n, m;
bool visitied[11][11][11][11];
queue<gusel> myq;
int ans = INT_MAX;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int move(int &x, int &y,int d1,int d2)
{
    int count = 0;
    while (arr[x + d1][y + d2] != '#' && arr[x][y] != 'O')
    {
        x += d1;
        y += d2;
        count++;
    }
    return count;
}

void bfs(int qweqweqw, int weweew)
{
    while (!myq.empty())
    {
        gusel t = myq.front();
        myq.pop();
        int rx = t.rx;
        int ry = t.ry;
        int bx = t.bx;
        int by = t.by;
        int cnt = t.cnt;

        for (int i = 0; i < 4; i++)
        {
            int bx1 = bx;
            int by1 = by;
            int rx1 = rx;
            int ry1 = ry;
            int rcount = move(rx1, ry1, dx[i], dy[i]);
            int bcount = move(bx1, by1, dx[i], dy[i]);
            //cout << rx1 << " " << ry1 << "\n";
            if (arr[bx1][by1] == 'O')
                continue;
            if (arr[rx1][ry1] == 'O')
            {
            
                ans = min(ans, cnt+1);
                continue;
                
            }
            if (bx1 == rx1 && by1 == ry1)
            {
                if (bcount > rcount)
                {
                    bx1 -= dx[i];
                    by1 -= dy[i];
                }
                else
                {
                    rx1 -= dx[i];
                    ry1 -= dy[i];
                }
            }
            if (visitied[rx1][ry1][bx1][by1] == true)
                continue;
            visitied[rx1][ry1][bx1][by1] = true;
            myq.push({ rx1,ry1,bx1,by1,cnt + 1 });
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int sx=0, sy=0, sb=0, sby=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'R')
            {
                sx = i;
                sy = j;
            }
            else if (arr[i][j] == 'B')
            {
                sb = i;
                sby = j;
            }
        }
    }myq.push({ sx,sy,sb,sby,0 });
    visitied[sx][sy][sb][sby] = true;
    bfs(0, 0);
    if (ans == INT_MAX)
        cout << -1;
    else
        cout << ans;
    return 0;
}