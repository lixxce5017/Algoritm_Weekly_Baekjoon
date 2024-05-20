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
int bfs();
void init();
bool chk();
bool chk()
{
   

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] ==1)continue;
            if (visitieid[i][j] == false)
                return false;
       
        }
    }
    return true;
}
void virusdfs(int idx, int cnt)
{
    if (cnt == virsu)
    {

        int res = bfs();
       
        if (chk() == true)
        {
          
            if (ans > res)
            {
                ans = res;
            }
            
        }
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
int bfs()
{
  
    queue<pair<int,int>>myq;
    for (int i = 0; i < virsu; i++)
    {
        int x = wall[i];
        visitieid[large[x].first][large[x].second] = true;
        myq.push(make_pair(large[x].first, large[x].second));
    }
    int cnt = 0;
    int res = 0;
    while (!myq.empty())
    {
        int s = myq.size();
        for (int q= 0; q< s; q++)
        {
            int x = get<0>(myq.front());
            int y = get<1>(myq.front());
          

            myq.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n)
                {
                    if (visitieid[nx][ny] == false && arr[nx][ny] != 1)
                    {
                      
                        visitieid[nx][ny] = true;
                        myq.push(make_pair(nx, ny));
                    }
                }
            }
        }
        if (myq.size() != 0)
            cnt++;
    } 
    return cnt;
}
void init()
{
    memset(visitieid, false, sizeof(visitieid));
   
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
    else
    {
        cout << ans;
    }
    return 0;

}