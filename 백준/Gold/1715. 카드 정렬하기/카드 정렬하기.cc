#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;
int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<int,vector<int>,greater<int>>pq;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        pq.push(temp);
    }
    int cnt = 0;
    while (pq.size()!=1)
    {
        int temp = pq.top();
        pq.pop();
        int temp2 = pq.top();
        pq.pop();
        cnt = cnt+temp2 + temp;
        pq.push(temp2+ temp);
        
    }
    cout << cnt;
}
