#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int tmp=0;
    int num=1;
    int ans=0;
    while(n>=a)
    {
        tmp=0;
        num=1;
        while(tmp<=n)
        {
            tmp=a*num;
            num++;
        }
        tmp=tmp-a;
        int tmp2=(tmp/a)*b;
        n=n-tmp+tmp2;
        ans+=tmp2;
        cout<<ans<<" ";
    }
    return ans;
}