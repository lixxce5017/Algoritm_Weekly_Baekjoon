#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,string> a,pair<int,string> b)
{
  return a.first< b.first;
}


int main()
{
  int num;
  int age;
  string name;
vector<pair<int,string>>v;
cin>>num;
  for (int i=0;i<num;i++)
    {
      cin>>age>>name;
      v.push_back(make_pair(age,name));
    }
  
  stable_sort(v.begin(),v.end(),compare);
  for(int i=0;i<num;i++)
    {
      cout<<v[i].first<<" "<<v[i].second<<'\n';
    }
 
}