#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<queue>
#include <climits>
#include<tuple>
#include<limits.h>
#include <cstring>
using namespace std;
typedef pair<int, int> Node;
void bfs(int x, int y);
int brige(int degre);
int arr[101][101];
bool visitied[101][101];
int ans[101][101];
int n;
int direction[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int cnt = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visitied[i][j] == false && arr[i][j] != 0)
            {
                cnt++;
                bfs(i, j);

            }
        }
    }
    memset(visitied, false, sizeof(visitied));
    int min = INT_MAX;
    int degree = 1;
    while (degree <= cnt)
    {
        int tep = brige(degree);
        degree++;
        memset(visitied, false, sizeof(visitied));
        memset(ans, 0, sizeof(ans));
        if (min > tep)
        {
            min = tep;
        }
    }

    cout << min;
}

void bfs(int x, int y)
{

    queue<Node> myq;
    myq.push(Node(x, y));
    arr[x][y] = cnt;
    while (!myq.empty())
    {

        int NowX = myq.front().first;
        int NowY = myq.front().second;    
        myq.pop();
        for (int i = 0; i < 4; i++)
        {
            int NexX = direction[i][0] + NowX;
            int NexY = direction[i][1] + NowY;
            if (NexX >= 0 && NexY >= 0 && NexX < n && NexY < n)

            {
                if (arr[NexX][NexY] == 1 && visitied[NexX][NexY] == false)
                {
                    arr[NexX][NexY] = cnt;
                    myq.push(Node(NexX, NexY));
                    visitied[NexX][NexY] = true;
                }

            }
        }
    }
    return;
}
//ans ,visitied 초기화 다 함
//정점 똑바로 들어감 ,할때마다 큐에 남은 것 없음
//첫번째만 똑바로 돌고 두번째부터 똑바로 안 돔;
int brige(int degre)
{
    queue<Node> qq;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (degre == arr[i][j])
            {
                qq.push(Node(i, j));
             
            }
        }
    }

    while (!qq.empty())
    {

        int NowX = qq.front().first;
        int NowY = qq.front().second;
        qq.pop();
     
        for (int i = 0; i < 4; i++)
        {
            int NexX = direction[i][0] + NowX;
            int NexY = direction[i][1] + NowY;
            if (NexX >= 0 && NexY >= 0 && NexX < n && NexY < n)
            {

                //바다 만날 시
                if (arr[NexX][NexY] == 0 && ans[NexX][NexY] == 0)
                {
                    qq.push(Node(NexX, NexY));
                    ans[NexX][NexY] = ans[NowX][NowY] + 1;
                }
                //다음 대륙을 만날 시
                else if (arr[NexX][NexY] != degre && arr[NexX][NexY] != 0)
                {
                    return ans[NowX][NowY];
                }
            }
        }
    }
    return 0;
}