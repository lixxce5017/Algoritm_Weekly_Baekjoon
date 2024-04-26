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
    out[node] = cnt-1;
}

void update_lazy(int startidx, int endidx, int node) {
    //일반적으로 생각해보면 너무 당연함
    if (lazy[node]) {
        tree[node] += (lazy[node] * (endidx - startidx + 1));
        if (startidx != endidx) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

ll getquery(int startidx, int endidx,int lidx, int ridx,int node) {
    update_lazy(startidx, endidx, node);
    if (ridx < startidx || lidx > endidx) return 0;
    if (lidx <= startidx && endidx <= ridx) return tree[node];
    int mid = (startidx + endidx) / 2;
    return getquery(startidx, mid, lidx,ridx, node * 2)+
        getquery(mid + 1, endidx, lidx,ridx, node * 2 + 1);
}

void update(int startidx, int endidx, int lidx, int ridx, ll up, int node) {
    //신속히 외우도록하자
    update_lazy(startidx, endidx, node);
    if (ridx < startidx || lidx > endidx) return;
    if (lidx <= startidx && endidx <= ridx) {
        tree[node] += (up * (endidx - startidx + 1));
        if (startidx != endidx) {
            lazy[node * 2] += up;
            lazy[node * 2 + 1] += up;
        }
        return;
    }

    int mid = (startidx + endidx) / 2;
    update(startidx, mid, lidx, ridx, up, node * 2);
    update(mid + 1, endidx, lidx, ridx, up, node * 2 + 1);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N>>M;
    int start = 0;
    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;
        if (temp == -1)
        {
            start = i;
        }
        else
        {
            arr[temp].push_back(i);
        }
    }
    dfs(start);
    int a, b, c;
    ll d;
    //for (int i = 1; i <= M; i++)
   // {
    //    cout << in[i] << " "<<out[i] << "\n";
    //}
    int mx = 0;
    //for (int i = 1; i <= N; i++) {
     //   mx = max(mx, out[i]);
    //}
    for (int i = 0; i < M; i++) {
        cin >> a;
        if (a== 1) {
            cin >> c >> d;
            update(1, N, in[c], out[c], d, 1);
        }
        else {
            cin >> b;
            cout << getquery(1, N, in[b],in[b], 1) << "\n";
        }

    }
   //for (int i = 0; i < N*4; i++)
    //{
    //    cout << tree[i] << " ";
    //}
    return 0;
}