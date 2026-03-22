#include <bits/stdc++.h>
using namespace std;
#define maxx 10000
int N, M;
vector<pair<int, int>> chapters;
int dp[21][201]; 
int dfs(int idx, int daysLeft) {
    if (idx == M) return 0;

    if (dp[idx][daysLeft] != -1) return dp[idx][daysLeft];

    dp[idx][daysLeft] = dfs(idx + 1, daysLeft);

    if (daysLeft >= chapters[idx].first) {
        dp[idx][daysLeft] = max(dp[idx][daysLeft],
                                dfs(idx + 1, daysLeft - chapters[idx].first) + chapters[idx].second);
    }
    return dp[idx][daysLeft];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    chapters.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> chapters[i].first >> chapters[i].second;
    }

    // DP 배열 초기화
    memset(dp, -1, sizeof(dp));

    cout << dfs(0, N) << "\n";

    return 0;
}
