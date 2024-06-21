#include <algorithm>
#include <vector>
#include <iostream>
typedef long long ll;
using namespace std;
struct Q
{
    ll x, y, val;
};
struct Seg
{
    ll l, r, lr, sum;
};
Seg tree[3000 * 4];
void init()
{
    for (int i = 0; i < 3000 * 4; i++)
    {
        tree[i].l = 0;
        tree[i].r = 0;
        tree[i].lr = 0;
        tree[i].sum= 0;
    }
}
Seg merge(Seg& a, Seg& b)
{
    Seg Res;
    Res.sum = a.sum + b.sum;
    Res.l = max(a.l, a.sum + b.l);
    Res.r= max(b.r, b.sum + a.r);
    Res.lr = max({ a.lr,b.lr,a.r + b.l ,Res.sum });
    return Res;
}
void update_seg(int node, int start, int end, int idx, ll val)
{
   // cout << node << " ";
    if (start>idx || end<idx)
    {
        return;
    }
    if (start == end)
    {
        tree[node].l += val;
        tree[node].r += val;
        tree[node].lr += val;
        tree[node].sum += val;
        return;
    }
    int mid = (start + end) / 2;
    update_seg(node * 2, start, mid, idx, val);
    update_seg(node * 2+1, mid+1, end, idx, val);
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n1,n2;
    cin >> n1;
    vector<ll>x;
    vector<ll>y;
    vector<Q> arr;
    vector < vector<pair<ll, ll>>> comper;
    for (int i = 0; i < n1; i++)
    {
        ll a, b,c;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
        arr.push_back({ a,b,1});
    }
    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        ll a, b, c;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
        arr.push_back({ a,b,-1 });
    }
    ll gain, losse;
    cin >> gain >> losse;
    comper.resize(n1+n2+1);
    sort( x.begin(), x.end());
    sort(y.begin(), y.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    y.erase(unique(y.begin(), y.end()), y.end());
    for (int i = 0; i < n1 + n2; i++)
    {
        ll x_t,y_t;
        x_t = lower_bound(x.begin(), x.end(), arr[i].x) - x.begin();
        y_t = lower_bound(y.begin(), y.end(), arr[i].y) - y.begin();
        if (arr[i].val == 1)
        {
            comper[y_t].push_back(make_pair(x_t,gain));
        }
        else
        {
            comper[y_t].push_back(make_pair(x_t, -losse));
        }
    
      
    }
    ll res = 0;
 
    for (int i = 0; i < n1+n2; i++)
    {
        //트리 초기화
        init();
        for (int j = i; j < n1 + n2; j++)
        {
            for (int k = 0; k < comper[j].size(); k++)
            {
                update_seg(1, 0, n1+n2-1, comper[j][k].first, comper[j][k].second);
            }
            res = max(res, tree[1].lr);
            
        }
    }
    cout << res;
}