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
pair<ll,ll> tree[MAX * 4];

//지금 이거 백터들 너무 큰거 들귀 재귀 뛰어서 메모리 초과 추정
//2퍼에서 메모리초과 오버플로우 안났는데 터짐
pair<long long, long long> min_idx(pair<long, long> x, pair<long, long> y)
{
    if (x.first == y.first)
    {
        if (x.second > y.second)
        {
            return y;
        }
        else
        {
            return x;
        }
    }
    else if (x.first > y.first)
    {
        return y;
    }
    else
    {
        return x;
    }

}
void init(int node, int start, int end) {
    if (start == end) {
        tree[node].second = start;
        tree[node].first =a[start] ;
        return;
    }
    int mid = (end + start) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    tree[node] = min_idx(tree[node * 2], tree[node * 2 + 1]);
}

pair<long long ,long long>sum(int node, int start, int end, int left, int right) {
    //구간이 아니면 1을 물려서 올려야지 답이 나옴
    if (left > end || right < start) {
        return { 1e9, 1e9 };
    }
    //계산 구간이 아닌 애들은 그냥 답만 올려보냄
    if (left <= start && end <= right) {
        return tree[node];
    }
    int mid = (end + start) / 2;
    return min_idx(sum(node * 2, start, mid, left, right), sum(node * 2 + 1, mid + 1, end, left, right));
}

void update(int node, int start, int end, int idx,long long val) {
    if (idx >end || start >idx) {
        return;
    }
    if (start==end) {
        tree[node].second = start;
        tree[node].first=val;
        return;
    }
    int mid = (end + start) / 2;
    update(node * 2, start, mid, idx, val);
    update(node * 2 + 1, mid + 1, end, idx, val);
    tree[node]= min_idx(tree[node*2],tree[node*2+1]);
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    init(1, 0, n - 1);
    cin >> m;
    while (m--) {
        long long t1, t2;
        long long t3;
        cin >> k;
        cin >> t2 >> t3;
        if (k == 1)
        {
            update(1, 0, n - 1, t2 - 1, t3);
        }
        else
        {
            cout << sum(1, 0, n- 1, t2 - 1, t3 - 1).second+1 << "\n";
        }

       
    }
 
    return 0;





}
