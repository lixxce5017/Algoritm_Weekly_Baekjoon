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
//dk 씨~발 실수로 e-s 해버려서 시간 날림
//지금 이거 백터들 너무 큰거 들귀 재귀 뛰어서 메모리 초과 추정
//2퍼에서 메모리초과 오버플로우 안났는데 터짐
long long init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = a[start];
    }
    return tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);

}
long long sum(int node, int start, int end, int left, int right) {
    //구간이 아니면 0을 물려서 합구하기
    if (left > end || right < start) {
        return 0;
    }
    //계산 구간이 아닌 애들은 그냥 답만 올려보냄
    if (left <= start && end <= right) {
        return tree[node];
    }
    int mid = (end +start) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

long long update(int node, int start, int end, int index, long long diff) {
    //그렇다면 인덱스 범위를 보는 것은 업데이트 해야할지 말지에 대한 구간을 보는 것
    if (index > end || index < start) {
        return tree[node];
    }
    //안걸리고 3에 3까지 왔다면 바뀌어야 할 노드인 것
    if (start == end) {
        return tree[node] = diff;
    }
    int mid = (end+start) / 2;
    //start 와 end는 구간을 말하는 것 입 몇번부터 몇번

    return tree[node] = update(2 * node, start, (start + end) / 2, index, diff) + update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    init(1, 0, n - 1);

    while (m--) {
        long long t1, t2;
        long long t3,t4;
        cin >> t1 >> t2 >> t3>>t4;
        long long small, big;
        if (t1 > t2)
        {
            small = t2;
            big = t1;
        }
        else
        {
            small = t1;
            big = t2;

        }
        cout << sum(1, 0, n - 1, small - 1, big - 1) << "\n";

        update(1, 0, n - 1, t3 - 1, t4);
            //3부터 6까지의 구간합
            a[t3- 1] = t4;
       
    }
    return 0;





}
