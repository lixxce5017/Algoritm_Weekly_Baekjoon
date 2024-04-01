#include <iostream>
#include<vector>
#include<cstring>
using namespace std;
bool visitied[501];
vector<int> v[501]; // 자신보다 작은 학생
vector<int> vd[501]; // 자신보다 큰 학생
//vector<vector<int>>로하면 시간초과 
//반고정 백터면 시간초과 안남  이유가 뭘까요?



//키순서 제일 중요한 포인트 내가 키 순서인지 알려면
// 내가 가는 곳 내가 오는 곳 노드가 n-1(나 제외) 이면 키 순서를 알 수 있다.
int order = 0;
void dfs(vector<int>arr[], int node)
{
    visitied[node] = true;
    for (auto i : arr[node])
    {
        if (visitied[i] == false)
        {
            visitied[i] = true;
            order++;
            dfs(arr,i);
        }
    }
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        vd[b].push_back(a);
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        order = 0;
        memset(visitied, false, sizeof(visitied));
        dfs(v,i);
        memset(visitied, false, sizeof(visitied));
        dfs(vd,i);
        if (order == n - 1)
        {
            res += 1;
        }
    }
    cout << res;
    return 0;
}