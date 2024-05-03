#include <string>
#include <vector>
#include<cmath>
using namespace std;

long long solution(long long n) {
    long long num=1;
    while(num<=n)
    {
        if(pow(num,2)==n)
        {
            return pow(num+1,2);
        }
        num++;
    }
    return -1;
}