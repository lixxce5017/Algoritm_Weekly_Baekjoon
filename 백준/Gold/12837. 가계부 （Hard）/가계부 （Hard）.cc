#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<tuple>
using namespace std;
#include <climits>
#include<cmath>
typedef long long ll;
#define MAX 1000021

ll a[MAX];
ll tree[MAX*4];
//굳이 귀찮게 초기화 말고 걍 남들처럼 4* 때리자


void updateQ(int node,int start, int end, int idx, long long val)
{
    if (start >idx || end < idx)
    {
        return ;
    }
    tree[node] += val;
    if (start == end)
    {   
        return;
    }
    int mid = (start + end) / 2;
     
    updateQ(node * 2, start, mid, idx, val);
  updateQ(node * 2+1, mid + 1, end, idx, val);
}

long long sumation(int node, int start, int end,int rangeA,int rangeB)
{
    if (start >rangeB || end <rangeA)
    {
        //범위 넘으면 넘겨줌
        return 0;
    }
    if (start >=rangeA&& end<=rangeB)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return  sumation(node * 2, start, mid,rangeA,rangeB) + sumation(node * 2 + 1, mid + 1, end,rangeA,rangeB);
}



int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //이미 열개짜리가 만들어져 있다 생각하자
    int n, m, k;
    cin >> n>>m;
    for (int i = 1; i <= m; i++) {
        int query;
        cin >> query;
        if (query == 1)
        {
            int idx;
            long long val;
            cin >> idx >> val;
            //업데이트
            updateQ(1, 1, n, idx, val);
        }
        else if(query)
        {
            int start, end;
            cin >> start >> end;
            cout << sumation(1, 1, n, start, end)<<"\n";
            //출력
        }
    }

 

 
 





}
