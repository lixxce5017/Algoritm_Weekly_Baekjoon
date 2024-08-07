#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int N;
int dp[5001];
int main() {
    cin >> N;
    dp[3] = 1;
    dp[5] = 1;
    for (int i = 6; i <= N; i++) {
        if (dp[i - 3]) {
            dp[i] = dp[i - 3] + 1;
        }
        if (dp[i - 5]) {
            dp[i] = dp[i - 5] + 1;
        }
    }
    if (dp[N]) 
        cout << dp[N];
    else
        cout << -1;
}
