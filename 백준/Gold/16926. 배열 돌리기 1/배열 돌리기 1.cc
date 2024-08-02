#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;
int arr[303][303];
bool visitied[303][303];
int n, m,k;
//북,남,서,동
int dx[4] = { -1,0 , 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int ans = 0;
void dfs()
{
    int num = min(n, m) / 2;
    for (int i = 0; i < num; i++)
    {
        //-1인 이유 배열 0,0기준 할꺼여서 아님 필요 없음
        int top = i;
        int left =i;
        int right = m - i-1;
        int bottom = n - i-1;
        int per = arr[top][left];
        for (int j = top+1; j <= bottom; j++)
        {
            swap(per, arr[j][left]);
        }
        for (int j = left+1; j <= right; j++)
        {

            swap(per, arr[bottom][j]);
        }
       for (int j = bottom-1; j >= top; j--)
        {
            swap(per, arr[j][right]);
       }
       for (int j = right-1; j >=left; j--)
       {
           swap(per, arr[top][j]);
       }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m>>k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    while (k)
    {
        dfs();
        k--;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
