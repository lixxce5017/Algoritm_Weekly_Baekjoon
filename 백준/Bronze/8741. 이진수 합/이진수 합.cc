#include<iostream>
using namespace std;
# define maxx 10 
int main(void)
{
    int N;
    cin >> N;
 
    for (int i = 0; i < N; i++)
    {
        cout << 1;
    }
    for (int i = 0; i < N-1; i++)
    {
        cout << 0;
    }
    return 0;
}