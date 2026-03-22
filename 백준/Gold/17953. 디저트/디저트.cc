#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> derste;
vector<vector<int>> dp;

int dfs(int day, int num) {
    if (day == N) 
        return 0;

    if (dp[day][num] != -1)
        return dp[day][num];

    int temp = 0;
    for (int i = 1; i <= M; i++) {
        if (num == i && num != 0)
            temp = max(temp, dfs(day + 1, i) + derste[day][i - 1] / 2);
        else
            temp = max(temp, dfs(day + 1, i) + derste[day][i - 1]);
    }
    dp[day][num] = temp;
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    derste.assign(N, vector<int>(M));
    dp.assign(N, vector<int>(M + 1, -1)); 

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> derste[j][i];
        }
    }

    cout << dfs(0, 0) << "\n";  
    return 0;
}
