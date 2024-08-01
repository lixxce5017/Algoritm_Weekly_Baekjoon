#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <cstring>
#include <limits.h>
#include <queue>

using namespace std;

int arr[54][54];
// 중복순열이다 1,1 연산도 해야함
struct cal {
    int r, c, s;
};

int temp[54][54];
bool selecting[10];
bool visited[54][54];
int copy_arr[54][54];
vector<int> v;
// 우 하 좌 상
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
vector<cal> cal_ro;
int n, m, k;

void rotate(int num) {
    int r = cal_ro[num].r - 1;
    int c = cal_ro[num].c - 1;
    int s = cal_ro[num].s;

    for (int layer = 1; layer <= s; ++layer) {
        int top = r - layer;
        int left = c - layer;
        int bottom = r + layer;
        int right = c + layer;

        int prev = arr[top][left];
        for (int i = left + 1; i <= right; ++i) {
            swap(prev, arr[top][i]);
        }
        for (int i = top + 1; i <= bottom; ++i) {
            swap(prev, arr[i][right]);
        }
        for (int i = right - 1; i >= left; --i) {
            swap(prev, arr[bottom][i]);
        }
        for (int i = bottom - 1; i >= top; --i) {
            swap(prev, arr[i][left]);
        }
    }
}

int ans = INT_MAX;

void dfs(int depth) {
    if (depth == cal_ro.size()) {
        int val2 = INT_MAX;
        for (int i = 0; i < n; i++) {
            int val = 0;
            for (int j = 0; j < m; j++) {
                val += arr[i][j];
            }
            val2 = min(val, val2);
        }
        ans = min(val2, ans);
        return;
    }

    for (int i = 0; i < cal_ro.size(); i++) {
        if (!selecting[i]) {
            selecting[i] = true;

            int backup[54][54];
            memcpy(backup, arr, sizeof(arr));

            rotate(i);
            dfs(depth + 1);

            memcpy(arr, backup, sizeof(arr));
            selecting[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    while (k--) {
        int a, b, c;
        cin >> a >> b >> c;
        cal_ro.push_back({ a, b, c });
    }

    dfs(0);
    cout << ans;
    return 0;
}
