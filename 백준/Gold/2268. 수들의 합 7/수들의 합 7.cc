#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include<stack>
#include<climits>

#define MAX 1000001
typedef long long ll;
using namespace std;

long long treeR[MAX*4];
class SegmentTree
{
public:
    long long update(int c, int s, int e, int idx, int x)
    {
        if (e <= idx || s > idx) return treeR[c];
        if (s + 1 == e) return treeR[c] = x;
        int m = (s + e) / 2;
        return treeR[c] = update(c * 2, s, m, idx, x) + update(c * 2 + 1, m, e, idx, x);
    }
    long long sum(int c, int s, int e, int sc, int ec)
    {
        if (ec <= s || sc >= e) return 0;
        if (sc <= s && e <= ec) return treeR[c];
        int m = (s + e) / 2;
        return sum(c * 2, s, m, sc, ec) + sum(c * 2 + 1, m, e, sc, ec);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m, a, b, c;
    SegmentTree tree;
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b >> c;
        if (a == 1) tree.update(1, 0, n, b - 1, c);
        else {
            if (b > c) { a = b; b = c; c = a; }
            cout << tree.sum(1, 0, n, b - 1, c) << "\n";
        }
    }
  
}