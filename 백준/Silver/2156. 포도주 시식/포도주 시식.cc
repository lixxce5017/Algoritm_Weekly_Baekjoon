
#include <iostream>
#include <string>
#include<math.h>
#include<vector>
using namespace std;

int dp[100010] = { 0, };
int arr[10006] = { 0, };
int main() {

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
 
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        dp[i] = max(dp[i], dp[i-2] + arr[i]);
        dp[i] = max(dp[i], dp[i - 3] + arr[i - 1] + arr[i]);
    }
    
    cout << dp[n];
    
}