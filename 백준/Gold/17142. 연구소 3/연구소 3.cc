#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;

typedef tuple<int, int, int> t;
int n, m, virsu;
int arr[52][52];
bool checkMap[52][52];
bool visitieid[52][52];
int copyMap[52][52];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int ans = INT_MAX;
vector<int>wall;
vector<pair<int, int>> large;
void virusdfs(int idx, int cnt);
void bfs();
void init();
void virusdfs(int idx, int cnt)
{
    if (cnt == virsu)
    {

        bfs();
        init();
        return;

    }

    for (int i = idx; i < large.size(); i++)
    {
        if (checkMap[large[i].first][large[i].second] == false)
        {
            checkMap[large[i].first][large[i].second] = true;
            wall.push_back(i);
            virusdfs(i, cnt + 1);
            checkMap[large[i].first][large[i].second] = false;
            wall.pop_back();
        }
    }
}
typedef tuple<int, int, int> tup;
void bfs()
{
    //최소 시간 구할꺼면 큐 만큼 반복문에서 돌면서 시작해야함
    queue<tup>myq;
    for (int i = 0; i < virsu; i++)
    {
        int x = wall[i];
        copyMap[large[x].first][large[x].second] = 3;
        visitieid[large[x].first][large[x].second] = true;
        myq.push(make_tuple(large[x].first, large[x].second, 0));
    }


    int cnt = -INT_MAX;
    while (!myq.empty())
    {

        int x = get<0>(myq.front());
        int y = get<1>(myq.front());
        int t = get<2>(myq.front());

        myq.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n)
            {
                if (visitieid[nx][ny] == false && copyMap[nx][ny] == 0)
                {
                    visitieid[nx][ny] = true;
                    if (t + 1 > cnt)
                    {
                        cnt = t + 1;
                    }
                    copyMap[nx][ny] = t + 1;
                    myq.push(make_tuple(nx, ny, t + 1));
                }
                if (visitieid[nx][ny] == false && copyMap[nx][ny] == 2)
                {
                    visitieid[nx][ny] = true;
                    copyMap[nx][ny] = 0;

                    myq.push(make_tuple(nx, ny, t+1));
                }
            }
        }
    }

    bool flag = true;



    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (copyMap[i][j] == 0&& visitieid[i][j]==false)
            {
                flag = false;
            }
        }
    }


    if (flag == true && cnt < ans)
    {
        ans = cnt;
    }

}
void init()
{
    memset(visitieid, false, sizeof(visitieid));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            copyMap[i][j] = arr[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> virsu;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            copyMap[i][j] = arr[i][j];
            if (arr[i][j] == 2)
            {
                large.push_back(make_pair(i, j));
            }
        }
    }

    virusdfs(0, 0);
    if (ans == INT_MAX)
    {
        cout << -1;
    }
    else if (ans == -INT_MAX)
    {
        cout << 0;
    }
    else
    {
        cout << ans;
    }
    return 0;

}