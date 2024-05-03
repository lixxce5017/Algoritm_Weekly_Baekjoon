#include <iostream>
#include<string>
using namespace std;
#include<stack>
int solution(string s)
{
    stack<char>mys;
    mys.push(s[0]);
    for(int i=1;i<s.size();i++)
    {
        
        if(!mys.empty()&&mys.top()==s[i])
        {
            
            mys.pop();
        }
        else
        {
            mys.push(s[i]);
        }
    }
    if(mys.empty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}