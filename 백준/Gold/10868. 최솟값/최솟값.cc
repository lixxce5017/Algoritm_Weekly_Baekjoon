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
#define MAX 1000001
const long long MOD = 1000000007;
ll a[MAX];
//굳이 귀찮게 초기화 말고 걍 남들처럼 4* 때리자
ll tree[MAX * 4];

//지금 이거 백터들 너무 큰거 들귀 재귀 뛰어서 메모리 초과 추정
//2퍼에서 메모리초과 오버플로우 안났는데 터짐
long long init( int node, int start, int end) {
    if (start == end) {
        return tree[node] = a[start];
    }
    return tree[node] = min(init(node * 2, start, (start + end) / 2), init(node * 2 + 1, (start + end) / 2 + 1, end));
}
long long sum(int node, int start, int end, int left, int right) {
    //구간이 아니면 1을 물려서 올려야지 답이 나옴
    if (left > end || right < start) {
        return MOD;
    }
    //계산 구간이 아닌 애들은 그냥 답만 올려보냄
    if (left <= start && end <= right) {
        return tree[node];
    }
    int mid = (end +start) / 2;
    return min(sum(node * 2, start, mid, left, right), sum( node *2+1,mid+ 1, end, left, right));
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    init( 1, 0, n - 1);

    while (m--) {
        long long t1,t2;
        long long t3;
        cin >>t2 >> t3;
   
         cout << sum( 1, 0, n - 1, t2 - 1, t3 - 1) << "\n";
    }
    return 0;

     



}
