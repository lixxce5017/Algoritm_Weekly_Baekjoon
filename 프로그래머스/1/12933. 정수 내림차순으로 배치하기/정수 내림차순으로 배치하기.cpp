#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string s;
    while(n)
    {
        s+=(n%10)+'0';
        n=n/10;
    }
   sort(s.begin(),s.end(),greater());
    cout<<s;
    long long dit=1;
    for (int i=s.size()-1;i>=0;i--)
    {
        answer+=(s[i]-'0')*dit;
        dit*=10;
    }
    return answer;
}