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
//굳이 귀찮게 초기화 말고 걍 남들처럼 4* 때리자
pair<ll, ll> tree[MAX * 4];


void init(int node, int start, int end) {
    if (start == end)
    {
        if (a[start] % 2 == 0)
        {
 
            tree[node].first = 1;
            tree[node].second = 0;
            return;
        }
        else
        {
            tree[node].second = 1;
            tree[node].first = 0;
            return;
        }
        
    }
    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2+1, mid+1,end);
    tree[node].first += tree[node*2].first;
    tree[node].second += tree[node * 2].second;
    tree[node].first += tree[node * 2+1].first;
    tree[node].second += tree[node * 2+1].second;
    return;
}

pair<long long, long long>sum(int node, int start, int end, int left, int right) {
    if (end<left||right<start)
        return pair<long long,long long>(0,0);
    if (left<=start && end<=right)
    {
        return tree[node];
    }
    int mid = (end +start) / 2;

    pair<long long, long long> leftnode = sum(node * 2, start, mid, left, right);
    pair<long long, long long> righttnode = sum(node * 2+1, mid+1, end, left, right);
    return pair<long long, long long>(leftnode.first + righttnode.first, righttnode.second + leftnode .second);

}

pair<long long, long long> update(int node, int start, int end, int idx, long long val) {
    if (idx < start || end < idx)
    {
        return tree[node];
    }
    if (start == end)
    {
        if (val % 2 == 0)
        {
            return tree[node] = pair<long long, long long>(1, 0);
        }
        else
        {
            return tree[node] = pair<long long, long long>(0, 1);
        }
        
    }
    int mid =(end + start) / 2;
    pair<long long, long long> leftnode = update(node * 2, start, mid, idx,val );
    pair<long long, long long> righttnode = update(node * 2 + 1, mid + 1, end,idx ,val );
    return tree[node]= pair<long long, long long>(leftnode.first+righttnode.first,leftnode.second+righttnode.second);
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m, k;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    init(1, 1, n);
    
    cin >> m;
    while (m--) {
        long long t1, t2;
        long long t3;
        cin >> k;
        if (k == 1)
        {
            cin >> t2 >> t3;
            update(1, 1, n, t2, t3);
        }
        else if(k==2)
        {
            cin >> t2 >> t3;
            cout << sum(1,1,n,t2,t3).first << "\n";
        }
        else
        {
            cin >> t2 >> t3;
            cout << sum(1, 1, n , t2 , t3 ).second << "\n";
        }


    }

    return 0;





}
