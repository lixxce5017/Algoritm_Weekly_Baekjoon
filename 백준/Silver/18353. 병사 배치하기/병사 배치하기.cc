#include <iostream>
#include<cstring>
using namespace std;
int n, soldier[2001], d[2001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> soldier[i];
        d[i] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++)
        {
            if (soldier[j] > soldier[i])
            {
                d[i] = max(d[i], d[j] + 1);
            
            }
        }
    }

    int maxN = 0;
    for (int i = 0; i < n; i++)
    {
        maxN = max(maxN, d[i]);
    }
    cout << n - maxN;
}