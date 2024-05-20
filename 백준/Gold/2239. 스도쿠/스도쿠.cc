#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;
int arr[11][11];
bool flag = false;
vector<pair<int, int>>target;
bool isNumSet(int n, int m)
{

    int cur = arr[n][m];
   
    for (int i = 0; i < 9; i++)
    {
        //현재 나 자신
        if (i == m)
            continue;
        if (cur ==arr[n][i])
            return false;
    }
    for (int i = 0; i < 9; i++)
    {
        if (i == n )
            continue;
        if (cur == arr[i][m])
            return false;
    }
    int r = n / 3;
    int c = m / 3;
    for (int i = r* 3; i < r * 3 + 3; i++)
    {
        for (int j = c * 3; j < c * 3 + 3; j++)
        {

            if (i == n && j == m)continue;
            if (cur == arr[i][j])
                return false;
        }
       
    }

    return true;

}
void dfs(int num)
{
   
    if (target.size() == num)
    {
  
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << arr[i][j];
            }
            cout << "\n";
        }
        flag = true;
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        arr[target[num].first][target[num].second] = i;
        if (isNumSet(target[num].first, target[num].second))
        {          
             dfs(num + 1);
            if (flag == true)
                return;
        }
        arr[target[num].first][target[num].second] = 0;
  }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 9; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 9; j++)
        {
            arr[i][j] = s[j] - '0';
            if (arr[i][j] == 0)
            {
               
                target.push_back(make_pair(i, j));
            }
        }
    }

    dfs(0);
    
  
    
     return 0;

}