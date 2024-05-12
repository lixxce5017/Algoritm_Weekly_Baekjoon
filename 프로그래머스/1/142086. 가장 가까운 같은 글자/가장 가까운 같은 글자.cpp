#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> arr(s.size());
    for(int i=0;i<s.size();i++)
    {
        bool falg=false;
            for(int j=i-1;j>=0;j--)
            {   if(s[j]==s[i])
            {    answer.push_back(abs(i-j));
                    falg=true;
             break;
            }
            }
        if(falg==false)
        {
            answer.push_back(-1);
        }
    }
    return answer;
}