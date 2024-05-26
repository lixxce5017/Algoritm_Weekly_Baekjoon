#include <iostream>

using namespace std;

#include <vector>
#include <algorithm>

string s;
int arr[10004];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int num, temp;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> temp;
        arr[temp]++;
    }

    for (int i = 0; i <= 10001; i++)
    {
        if (arr[i] != 0)
        {
            while (arr[i] > 0)
            {
                cout << i << "\n";
                arr[i]--;
            }
        }
    }
}