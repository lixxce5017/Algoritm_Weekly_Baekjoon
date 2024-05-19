#include <iostream>
#include <string>
#include<math.h>
#include<vector>
#include<queue>
#include <climits>
#include<algorithm>
using namespace std;
int arr[2000] = { 0, };
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int cnt = 0;
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        int nowVal = arr[i];
        int start = 0;
        int end = n - 1;
        //<=딱히 상관 없는데 얘도넣으면70 나가리
        while (start < end)
        {

            int sum = arr[start] + arr[end];
            if (sum == nowVal)
            {
                if (i == start)
                {//arr[i] == arr[end]조건으로 하면 60 몇에서 나가리인가?

                    start++;
                }
                else if (i == end)
                {
                    end--;
                }
                else {
                    cnt++;
                    break;
                   
                }
            }
            else if (sum > nowVal)
            {

                end--;
            }
            else
            {

                start++;
            }
            //원 포문 앞에서부터 보는건 왜 안되는 것인가?
        }
    }
    cout << cnt;
    return 0;
}
