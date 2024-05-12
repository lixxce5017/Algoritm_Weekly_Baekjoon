#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    int i;
    bool answer = true;

   
   
    if (s.size() ==4 || s.size() ==6)
    {
        for (i = 0; i < s.size(); i++)
        {
            if ((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
            {
                 answer = false;
                break;
            }
   
        }
   
      }
    else
    {
        answer = false;
        
    }
    return answer;
}