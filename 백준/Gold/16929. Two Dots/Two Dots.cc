#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include<stack>
#include<climits>

#define MAX 1000001
typedef long long ll;
using namespace std;
char val[1003][1003];
int visitied[1003][1003];
int chk[1003][1003];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, m;
int cnt;
bool truth = false;
void dfs(int x, int y, char value, int count, int count2, int perx,int pery)
{
    //1이 다운
    chk[x][y] = count2;

    //cout << x << " " << y << "\n";
    for (int i = 0; i < 4; i++)
    {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        visitied[nx][ny] = cnt;
        if (nx < n && ny < m && nx >= 0 && ny >= 0)
        {
            //가지치기 1
            if (val[nx][ny] != value)
            {
                continue;
            }
            else if (nx == perx && ny == pery && chk[nx][ny] == count2 && count >= 4 && val[nx][ny] == value)
            {
                cout << "Yes";
                exit(0);
                return;
            }
            //뒤로 빠꾸해 오는걸 어찌 막지?
            else if (val[nx][ny] == value && chk[nx][ny] == 0)
            {
                dfs(nx, ny, value, count + 1, count2, perx, pery);

            }
                
        }
    }
    cnt++;
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n>>m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            val[i][j] = s[j];
        }
    }
    //집합?
    int q=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
  
                q++;
                dfs(i, j, val[i][j], 1, q,i,j);
                memset(chk, 0, sizeof(chk));
        }
    }
    cout << "No";
}