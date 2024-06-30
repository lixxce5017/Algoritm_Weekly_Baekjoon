#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<queue>
#include<stack>
#include<tuple>
#include<limits.h>
using namespace std;
#define maxx 989999

int ar[100005];
int n, k;

inline int mid(int stt, int end) { return stt + (end - stt) / 2; }

int init(vector<int>& tree, int node, int start, int end)
{
    if (start == end) return tree[node] = ar[start];
    int m = mid(start, end);
    return tree[node] = init(tree, node * 2, start, m) * init(tree, node * 2 + 1, m + 1, end);
}

int update(vector<int>& tree, int node, int start, int end, int idx, int diff)
{
    if (idx < start || idx > end) return tree[node];
    if (start == end) return tree[node] = diff;

    int m = mid(start, end);
    return tree[node] = update(tree, node * 2, start, m, idx, diff) * update(tree, node * 2 + 1, m + 1, end, idx, diff);
}

int query(vector<int>& tree, int node, int start, int end, int l, int r)
{
    if (l <= start && end <= r) return tree[node];
    if (start > r || end < l) return 1;
    int m = mid(start, end);
    return query(tree, node * 2, start, m, l, r) * query(tree, node * 2 + 1, m + 1, end, l, r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    while (!cin.fail())
    {
        string result("");
        vector<int> segtree(n * 4);

        for (int i = 1; i <= n; ++i)
        {
            int x;
            cin >> x;
            if (x > 0)
                x = 1;
            else if (x < 0)
                x = -1;
            ar[i] = x;
        }

        init(segtree, 1, 1, n);

        for (int i = 0; i < k; ++i)
        {
            char order;
            int a, b;
            cin >> order >> a >> b;

            if (order == 'C')
            {
                int diff = 0;
                if (b > 0)
                    diff = 1;
                else if (b < 0)
                    diff = -1;

                ar[a] = diff;
                update(segtree, 1, 1, n, a, diff);
            }
            else
            {
                int calc = query(segtree, 1, 1, n, a, b);
                if (!calc)
                    result.push_back('0');
                else if (calc > 0)
                    result.push_back('+');
                else
                    result.push_back('-');
            }
        }

        cout << result << '\n';
        cin >> n >> k;
    }
}