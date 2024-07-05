#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

bool visited[501][501] = { false, };

char arr[501][501] = { 0, };

int maxx = 0, n, m, ans = 0, flag = -1;

int start_x, start_y;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int x, int y, int depth)
{
  
    //cout << x << " " << y << "\n";
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx == start_x && yy == start_y&& visited[xx][yy]==true&& depth >= 4)
        {
            //cout << "d";
            flag = 1;
            cout<< "Yes";
            exit(0);
        }

        if (visited[xx][yy] == false && xx >= 0 && yy >= 0 && xx < n && yy < m && arr[x][y] == arr[xx][yy])
        {
            visited[xx][yy] = true;
            dfs(xx, yy, depth + 1);
            visited[xx][yy] = false;
        }
    }
}

int main()
{
    char a;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a;
            arr[i][j] = a;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = true;
            start_x = i;
            start_y = j;
            dfs(i, j, 1);
            visited[i][j] = false;
        }
    }
        cout << "No";
}