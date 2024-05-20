#include <iostream>
#include<algorithm>
using namespace std;
int main(int argc, const char *argv[])
{
  string bigger;
  string a,b;
  cin>>a>>b;

  for(int i=2; i>=0;i--)
    {
      if(a[i]>b[i])
      {
        bigger=a; break;
      }
      else if(a[i]<b[i])
      {
        bigger=b; break;
      }
    }
  cout<<bigger[2]<<bigger[1]<<bigger[0];
    
}