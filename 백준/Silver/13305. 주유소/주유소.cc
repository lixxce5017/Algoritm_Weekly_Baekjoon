#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include<stack>

#define MAX 1000001
typedef long long ll;
using namespace std;
ll val[100003];
ll node[100003];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> node[i];
    }
    ll cost = 0;
    ll oil = node[0];
    for (int i = 0; i < n-1; i++)
    {
        oil = min(node[i], oil);
        cost += (oil * val[i]);
    }
    cout << cost;
}