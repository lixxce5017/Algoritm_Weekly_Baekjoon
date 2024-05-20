#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;

typedef tuple<int, int, int> t;
int n;
pair<int, int>arr[10];
pair<int, int>copyMap[10];
int ans = 0;

/*
8
7 100
6 100
100 1
100 1
100 1
100 1
100 1
100 1


3

1 58

105 24

39 203

3

102 250

28 140

247 111

3

78 276

60 106

183 204


3

3 151

113 75

151 208

*/

//0이 hp 1이 attack
void dfs(int now);
void dfs(int now)
{
    if (now == n)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {

            if (arr[i].first <= 0)
            {
                count++;
            }
        }

        if (ans < count)
        {
            ans = count;
        }
        return;
    }
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (i == now || arr[i].first <= 0||arr[now].first<=0)
            continue;
        flag = true;
        arr[now].first = arr[now].first - arr[i].second;
        arr[i].first = arr[i].first - arr[now].second;
        dfs(now + 1);
        arr[now].first = arr[now].first + arr[i].second;
        arr[i].first = arr[i].first + arr[now].second;
    }
    if (flag == false)
    {
        dfs(now + 1);
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
        copyMap[i].first = arr[i].first;
        copyMap[i].second = arr[i].second;
    }
    dfs(0);

    cout << ans;
}