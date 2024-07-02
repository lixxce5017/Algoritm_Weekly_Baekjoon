#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<queue>
#include<stack>
#include<tuple>
#include<limits.h>
#include<queue>
using namespace std;
int parent[100003];
int find(int a)
{
    if (a == parent[a])
    {
        return a;
    }
    return parent[a]=find(parent[a]);
}

void uion(int a, int b)
{
     a = find(a);
     b = find(b);
    if (a != b)
    {
       parent[a] = b;
    }   
}
priority_queue < pair<int, pair<int, int>>, vector < pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>mqe;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        mqe.push({ c,{a,b} });
    }
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }
    int use = 0;
    int sum2 = 0;
    while (use < n - 1)
    {

        int val = mqe.top().first;
        int a = mqe.top().second.first;
        int b = mqe.top().second.second;
        mqe.pop();
        if (find(a) != find(b))
        {
            uion(a, b);
            sum2 += val;
            sum = max(val, sum);
            use++;
        }
    }
    cout << sum2-sum;
}