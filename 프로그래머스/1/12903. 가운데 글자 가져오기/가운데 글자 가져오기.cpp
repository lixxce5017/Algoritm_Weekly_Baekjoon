#include <string>
#include <vector>

using namespace std;

string solution(string s) {
   
    string ans;
    if(s.size()%2!=0)
    {
        ans+=s[s.size()/2];
    }
    else
    {        ans+=s[s.size()/2-1];
        ans+=s[s.size()/2];

    }
    return ans;
}