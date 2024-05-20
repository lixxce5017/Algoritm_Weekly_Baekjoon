#include <iostream>
#include <algorithm>
#include <vector>
#include<stdio.h>
#include<deque>
#include<cstring>
#include<cstdlib>
#include<stack>
#include<string>
using namespace std;
int arr[10003] = { 0, };
int sense[10003] = { 0, };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    //1 3 6  6 7 9
    for (int i = 1; i <n; i++)
    {
        sense[i] =arr[i] - arr[i-1];
      
    }
    sort(sense, sense + n);
    int len = 0;
    for (int i = 0; i < n - k + 1; i++)
    {
        len += sense[i];
    }
    cout << len;
    return 0;
}


