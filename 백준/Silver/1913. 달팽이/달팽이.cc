#include <iostream>
#include <string>
#include<vector>
#include<cmath>
using namespace std;

int arr[1001][1001] = { 0, };
int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int find = n;

    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0,0,-1,1 };

    int size = 3;
    int x = n / 2;
    int y = n / 2;

    arr[x][y] = 1;
    int num = 2;
    int down = 0;
    int up = 0;
    int right = 0;
    int left = 0;
    while (x != 0 || y != 0)
    {
        while (num <= size * size)
        {
            //값 할당
            if (x==(n / 2)&& y == (n / 2))
            {
                down = size - 1;
                up = size;
                right = size - 2;
                left = size - 1;
                up--;
                x = dx[0] + x;
                y = dy[0] + y;
            }
            //0번째 up,1번째 다운 2번째 오른쪽 3번째 왼쪽

            
             else if (right > 0)
            {
                x = dx[3] + x;
                y = dy[3] + y;

                right--;

            }
             
             
            else if (down > 0)
            {
                x = dx[1] + x;
                y = dy[1] + y;

                down--;

            }
            else if (left > 0)
            {
                x = dx[2] + x;
                y = dy[2] + y;

                left--;

            }
            else
            {
             x = dx[0] + x;
             y = dy[0] + y;
             up--;

            }
         
            arr[x][y] = num;
            num++;

        }
        size = size + 2;
        n = n - 2;
    }
    
int sy = 0, sx = 0;
for (int i = 0; i <find; i++)
{
    for (int j = 0; j < find; j++)
    {
        cout << arr[i][j] << " ";
        if (arr[i][j] == k)
        {
            sx = i;
            sy = j;
        }
    }
    cout << "\n";
}
cout << sx+1 << " " << sy+1;
return 0;
}