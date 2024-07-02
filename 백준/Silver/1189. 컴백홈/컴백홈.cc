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

int R, C, K, ans;
char board[6][6];
bool vis[6][6];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void dfs(int x, int y, int dist) {
    if (K==dist && x==1 &&y==C) {
         ans++;
        return;
    }

    for (int d = 4; d--;) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx<1 || nx>R || ny<1 || ny>C) continue;
        if (vis[nx][ny] || board[nx][ny] == 'T') continue;
        vis[nx][ny] = true;
        dfs(nx, ny, dist + 1);
        vis[nx][ny] = false;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C >> K;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            cin >> board[i][j];

 //   if (K < R + C - 1) {
 //      cout << 0;
 //      return 0;
  //  }

    vis[R][1] = true;
    dfs(R, 1, 1);

    cout << ans;
}