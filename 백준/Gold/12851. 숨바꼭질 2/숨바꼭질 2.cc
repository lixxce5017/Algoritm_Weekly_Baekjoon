#include <iostream>
#include <string>
#include<math.h>
#include<vector>
#include<queue>
#include <climits>
#include<algorithm>
using namespace std;
bool visitied[100003];
int start, endd;
int res = 0;
bool falg = true;
int cnt = 0;
void bfs(int start, int  end)
{
    queue<pair<int, int>>myq;
    myq.push(make_pair(0, start));
    while (!myq.empty())
    {
        int nowNode = myq.front().second;
        int nowVal = myq.front().first;
        myq.pop();
        if (nowNode == end&&falg==true)
        {
            cout << nowVal << "\n";
            res = nowVal;
            cnt++;
            falg = false;
        }
        if (nowVal == res&&nowNode==endd)
        {
            cnt++;
            
        }
        visitied[nowNode] = true;
        if (nowNode + 1 <= 100000 && visitied[nowNode + 1] == false)
        {
            myq.push(make_pair(nowVal + 1, nowNode + 1));
        }
        if (nowNode - 1 >=0 && visitied[nowNode - 1] == false)
        {
            
            myq.push(make_pair(nowVal + 1, nowNode - 1));
        }
        if (nowNode * 2 <= 100000 && visitied[nowNode * 2] == false)
        {
            myq.push(make_pair(nowVal + 1, nowNode * 2));
        }

    }
    cout << cnt-1;
}

void intput()
{
    cin >> start >> endd;
    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    intput();
    bfs(start, endd);
    return 0;
}
