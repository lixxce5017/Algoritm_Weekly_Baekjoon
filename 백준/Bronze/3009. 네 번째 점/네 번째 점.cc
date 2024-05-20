
#include <iostream>
using namespace std;
int main()
{
    int x1,x2,y1,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    int ax=0;
    int ay=0;
    if(x1==x2)
        ax=x3;
    else if(x3==x2)
        ax=x1;
    else if(x1==x3)
        ax=x2;
    if(y1==y2)
        ay=y3;
    else if(y3==y2)
        ay=y1;
    else if(y1==y3)
        ay=y2;
    
    cout<<ax<<" "<<ay;
    return 0;
}
