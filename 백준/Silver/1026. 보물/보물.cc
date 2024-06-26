#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    vector<int> sum(n, 0);
    int min = 0;
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    sort(a.begin(),a.end());
    sort(b.begin(), b.end(),greater<>());
    for (int i = 0; i < n; i++)
    {
        num += a[i] * b[i];
    }

    cout << num<<"\n";

}