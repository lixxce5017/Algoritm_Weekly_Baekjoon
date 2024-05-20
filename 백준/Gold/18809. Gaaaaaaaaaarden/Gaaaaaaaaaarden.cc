#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;

typedef tuple<int, int, int> t;
int n,m,green,red;
int arr[52][52];
bool checkMap[52][52];
int check_green[52][52];
int check_red[52][52];
int copyMap[52][52];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int flower = 0;
int ans;
vector<int>redCulture;
vector<int>greenCulture;
vector<pair<int,int>> large;
void greendfs(int idx, int cnt);
void reddfs(int idx,int cnt);
void bfs();
void init();
void greendfs(int idx,int cnt)
{
    if (cnt == green)
    {
        reddfs(0,0);
    }
    for (int i = idx; i < large.size(); i++)
    {
        if (checkMap[large[i].first][large[i].second] == false)
        {
            checkMap[large[i].first][large[i].second] = true;
            greenCulture.push_back(i);
   
            greendfs(i,cnt+1);
            checkMap[large[i].first][large[i].second] = false;
            greenCulture.pop_back();
        }

    }
}
void reddfs(int idx,int cnt)
{
    if (cnt == red)
    {
        bfs();


        init();
    }
    for (int i = idx; i < large.size(); i++)
    {
        if (checkMap[large[i].first][large[i].second] == false)
        {
            checkMap[large[i].first][large[i].second] = true;
            redCulture.push_back(i);
            reddfs(i, cnt + 1);
            checkMap[large[i].first][large[i].second] = false;
            redCulture.pop_back();
        }

    }
}
void bfs()
{
    //4가 red 
    //3이 green
    queue<t> redque;
    queue<t> greenque;
    flower = 0;
    for (int i = 0; i < red; i++)
    {
        int x = redCulture[i];
      
        copyMap[large[x].first][large[x].second]=4;
        check_red[large[x].first][large[x].second] = 1;
        redque.push(make_tuple(large[x].first, large[x].second,1));
    }
    for (int i = 0; i < green; i++)
    {
        int x = greenCulture[i];
   
        copyMap[large[x].first][large[x].second] = 3;
        check_green[large[x].first][large[x].second] = 1;
        greenque.push(make_tuple(large[x].first, large[x].second, 1));
    }

    //당연히 첫 스타트에 여러개 넣었으니
    //여러개 돌려야함
    while (!redque.empty() || !greenque.empty())
    {
        int redsize = redque.size();
        for (int k = 0; k < redsize; k++)
        {
            t now =redque.front();
            int x = get<0>(now);
            int y = get<1>(now);
            int z = get<2>(now);
            redque.pop();
            if (copyMap[x][y] == -1) continue;
    
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m)
                {
                    if (check_red[nx][ny] == 0 && (copyMap[nx][ny] == 1 || copyMap[nx][ny] == 2))
                    {
                        check_red[nx][ny] = z + 1;
                        copyMap[nx][ny] = 3;
                        redque.push(make_tuple(nx, ny, z + 1));
                    }
                }
            }
        }
      
        int greensize = greenque.size();
        for (int k = 0; k < greensize; k++)
        {
            t now = greenque.front();
           
            int x = get<0>(now);
            int y = get<1>(now);
            int z = get<2>(now);
            greenque.pop();
   
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m)
                {
                    if (check_green[nx][ny] == 0 && (copyMap[nx][ny] == 1 || copyMap[nx][ny] == 2))
                    {
                        check_green[nx][ny] = z + 1;
                        copyMap[nx][ny] = 4;
                        greenque.push(make_tuple(nx, ny, z + 1));
                    }
                    else if (check_green[nx][ny] == 0 && copyMap[nx][ny] == 3)
                    {
                        if (check_red[nx][ny] == z + 1)
                        {
                            copyMap[nx][ny] = -1;
                            check_green[nx][ny] = z + 1;
                        }
                    }
                }
            }
        }
    }
 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (copyMap[i][j] == -1)
            {
                flower++;
            }
        }
    }
    ans = max(flower, ans);
}
void init()
{
    memset(check_green, 0, sizeof(check_green));
    memset(check_red, 0, sizeof(check_red));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            copyMap[i][j] = arr[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n>>m>>green>>red;
   
  
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            copyMap[i][j] = arr[i][j];
            if (arr[i][j] == 2)
            {
                large.push_back(make_pair(i, j));
            }
        }
   }

    greendfs(0, 0);
    cout << ans;
     return 0;

}