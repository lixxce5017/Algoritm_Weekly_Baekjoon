#include<iostream>
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    int num=0;
    while(count!=num)
    {
        num++;
        answer+=(price*num);
    }
    cout<<answer;
    answer=answer-money;
    if(answer<=0)
    {
        return 0;
    }
    return answer;
}