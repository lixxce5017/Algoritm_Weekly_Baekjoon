#include <iostream>
#include <algorithm>
#include <vector>
#include<stdio.h>
#include<queue>
#include<cstring>
#include<cstdlib>
using namespace std;
vector<pair<int, int>>Convenience;
bool visitedX[101];
pair<int, int> rock;
pair<int, int> start;
bool bfs(int x, int y);
//쉽게 접근하는 방법 : 편의점 없이 갈 수 있는 거리는 최대 50m * 20병 = 1000m 라는 것!
//즉, 현재 좌표와 이동하려는 곳의 거리 차가 1000 이하면 이동할 수 있는 것이다!
bool bfs(int x, int y)
{
    int Csize = Convenience.size();
    queue <pair<int, int>>que;
    que.push(make_pair(x, y));
    while (!que.empty())
    {
        int nx = que.front().first;
        int ny = que.front().second;
        que.pop();
            if (abs(nx - rock.first) + abs(ny - rock.second)<= 1000)
            {
                return true;
            }
        for (int i = 0; i < Csize; i++)
        {
            if (visitedX[i]==true)
            {
                continue;
            }
          
            if (abs(nx-Convenience[i].first) +abs(ny-Convenience[i].second)<=1000)
            {
                visitedX[i] = true;
                que.push(make_pair(Convenience[i].first, Convenience[i].second));
            }
        }    
       
    }
    return false;
}
void init()
{
    rock.first = 0;
    rock.second = 0;
    start.first = 0;
    start.second = 0;
    while (!Convenience.empty())
    {
        Convenience.pop_back();
    }
    memset(visitedX, false,sizeof(visitedX));

}
int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t)
    {
        int n;
        cin >> n;
        cin >> start.first >> start.second;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            Convenience.push_back(make_pair(a, b));
        }
        cin >> rock.first >> rock.second;

        bool ans=bfs(start.first,start.second);
        if (ans == true) cout << "happy" << "\n";
        else cout << "sad" << "\n";
        init();
        t--;
        
    }
 

}


