#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>


#define MAX 1000001
typedef long long ll;
using namespace std;
int N, M, K;
vector<ll>arr[MAX];
ll tree[MAX * 4];
ll lazy[MAX * 4];
int in[MAX];
int out[MAX];
bool visitied[MAX];
int cnt = 1;
//회사문화 +xor 문제
// xor에 %2를 해주는 것을 잊지말자
// a ^a=0 자기 자신에게 수행할 경우 결과값은 무조건 0이다 xor은
//이 (end - start + 1) % 2 == 1이라면 lazy[idx]를 한 번 xor하고, 
//그렇지 않다면 원래 tree값이 그대로 보존된다.
//xor를 홀수번 하면 1번 한 것과 같고, 짝수번 하면 안한 것과 같다

//1. a ^ 0 == a

//2. a ^ a == 0

//3. a ^ b ^ b == a ^ (b ^ b) == a ^ 0 == a

//짝수번 하게 된다면 0이되기 때문에 %2로 1과 0으로 0이면 그대로
//1이면 한 번 한다.
void dfs(int node)
{
    visitied[node] = true;
    in[node] = cnt++;
    for (auto i : arr[node])
    {
        if (visitied[i] == false)
        {
            dfs(i);
        }
    }
    out[node] = cnt - 1;
}


void update_lazy(int startidx, int endidx, int node) {
    //일반적으로 생각해보면 너무 당연함
    if (lazy[node]) {
        tree[node] ^= lazy[node] * ((endidx - startidx + 1) % 2);
        if (startidx != endidx) {
            lazy[node * 2] ^= lazy[node];
            lazy[node * 2 + 1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

ll getquery(int startidx, int endidx, int lidx, int ridx, int node) {
    update_lazy(startidx, endidx, node);
    if (ridx < startidx || lidx > endidx) return 0;
    if (lidx <= startidx && endidx <= ridx) return tree[node];
    int mid = (startidx + endidx) / 2;
    return getquery(startidx, mid, lidx, ridx, node * 2) ^
        getquery(mid + 1, endidx, lidx, ridx, node * 2 + 1);
}

void update(int startidx, int endidx, int lidx, int ridx, ll up, int node) {
    //신속히 외우도록하자
    update_lazy(startidx, endidx, node);
    if (ridx < startidx || lidx > endidx) return;
    if (lidx <= startidx && endidx <= ridx) {
        tree[node] ^= up * ((endidx - startidx + 1)%2);
        if (startidx != endidx) {
            lazy[node * 2] ^= up;
            lazy[node * 2 + 1] ^= up;
        }
        return;
    }

    int mid = (startidx + endidx) / 2;
    update(startidx, mid, lidx, ridx, up, node * 2);
    update(mid + 1, endidx, lidx, ridx, up, node * 2 + 1);
    tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    int start = 0;
    for (int i = 1; i <= N-1; i++) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    dfs(1);
    int a, b, c;
    ll d;

    int mx = 0;
    for (int i = 1; i <= N; i++)
    {
        ll num;
        cin >> num;
        update(1, N, in[i], in[i], num,1);
    }

    for (int i = 0; i < M; i++) {
        cin >> a;
        if (a == 2) {
            cin >> c >> d;
            update(1, N, in[c], out[c], d, 1);
        }
        else {
            cin >> b;
            cout << getquery(1, N, in[b], out[b], 1) << "\n";
        }

    }
    //for (int i = 0; i < N*4; i++)
     //{
     //    cout << tree[i] << " ";
     //}
    return 0;
}