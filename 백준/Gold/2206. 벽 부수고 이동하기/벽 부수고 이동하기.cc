#include<iostream>
#include<queue>
#include<string.h>
#include<tuple>

using namespace std;
int n, m;

typedef tuple<int, int, int>node;
int visitied[1003][1003][2];
int map[1004][1004] = { 0, };
int coordinate[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
void bfs() {
    queue<node>myq;
    visitied[1][1][0] = 1;
    //x,y, 뚫었는지 안뚫었는지
    myq.push(node(1, 1, 0));
  
    while (!myq.empty())
    {
        node no = myq.front();
        int nox = get<0>(no);
        int noy = get<1>(no);
        int puOr = get<2>(no);
        myq.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = coordinate[i][0] + nox;
            int ny = coordinate[i][1] + noy;
            
            //0이면 가는 경우
            if (nx > 0 && ny > 0 && nx <= n && ny <= m && map[nx][ny] == 0)
            {
   
                if (visitied[nx][ny][0] ==0)
                {
                    if (puOr == 0)
                    {
                        visitied[nx][ny][0] += visitied[nox][noy][0] + 1;
                        myq.push(node(nx, ny, puOr));

                    }
                }
                if (visitied[nx][ny][1]==0)
                {
                     if (puOr == 1)
                {
                    visitied[nx][ny][1] += visitied[nox][noy][1] + 1;
                    myq.push(node(nx, ny, puOr));

                }
                }
                
            }//현재 다 0으로 쭉가면 18인데 1로 한 번 뚫으면 14가 나오는 부분이 틀림
            if (nx > 0 && ny > 0 && nx <= n && ny <= m && puOr==0&&map[nx][ny]==1)
            {
                if (visitied[nx][ny][1]==0)
                {
                    visitied[nx][ny][1] += visitied[nox][noy][0] + 1;
                    myq.push(node(nx, ny, puOr+1));
               
                }
            }
        }
    }
    //둘 중 하나가 영인 경우 그리고 둘 다 수가 있으면 -1 해야함
   
    if (visitied[n][m][1] > 0 || visitied[n][m][0] > 0)
    {
        if (visitied[n][m][1] > 0&& visitied[n][m][0]==0)
        {
            cout << visitied[n][m][1];
        }
        else if (visitied[n][m][0] > 0 && visitied[n][m][1] == 0)
        {
            cout << visitied[n][m][0];
        }
        else
        {
            cout<< min(visitied[n][m][1], visitied[n][m][0]);
        }
    }
    else
    {
        cout << -1;
    }
    return;
}
void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            map[i][j + 1] = s[j] - '0';
        }
    }
    bfs();
    return;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();

    return 0;
}