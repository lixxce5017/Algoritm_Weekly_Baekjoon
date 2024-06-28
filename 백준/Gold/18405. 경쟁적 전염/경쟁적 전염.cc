#include <cstdio>
#include <algorithm>
#include <vector>
#include<iostream>
#include<queue>
using namespace std;
int arr[203][203];
int visitied[203][203];
//시간이 낮은것부터 증식 같다면 우선순위가 낮은 것 부터 증식
//그걸로 우선순위큐와 비교
struct Node
{
    int x; int y; int type; int time;
    bool operator()(const Node& a,const Node& b) {
        if (a.time == b.time)
        {
            return a.type > b.type;
        }
        else
            return a.time > b.time;
    }
};

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    priority_queue<Node, vector<Node>, Node>qu;
  
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] != 0)
            {
                qu.push({ i,j,arr[i][j],0 });
                visitied[i][j] = arr[i][j];
            }
        }
    }
    int t, ex, ey;
    cin >> t >> ex >> ey;
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { 1,-1,0,0 };
    while (!qu.empty())
    {
        Node tmp = qu.top();
        qu.pop();
        int x = tmp.x;
        int y = tmp.y;
        // cout << x << " " << y << "\n";
        int type = tmp.type;
        int time = tmp.time;
        if (time == t)
        {
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n)
            {
                if (visitied[nx][ny] == 0)
                {
                    qu.push({ nx, ny, type, time + 1 });
                    visitied[nx][ny] = type;
                }
            }
        }

    }
               cout << visitied[ex - 1][ey - 1];
    return 0;
}