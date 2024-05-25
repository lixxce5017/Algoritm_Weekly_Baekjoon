#include <stdio.h>
#include<string.h>

int main()
{
    int len=0,cnt=0;
    char ch[101];
    
    scanf("%s",ch);
    
    
    
    for (int i=0 ; i<strlen(ch) ; i++)
    {
        if (ch[i]=='c' && i!=strlen(ch)-1) //c 경우
        {
            if(ch[i+1]=='='||ch[i+1]=='-')
            {
                cnt++;
                i++;
            }
            else
            {
                cnt++;
            }
        }
        
        else if(ch[i]=='d' && (i<strlen(ch)-2||i<strlen(ch)-1)) //d
        {
            if(ch[i+1]=='z')
            {
                if(ch[i+2]=='=')
                {
                    cnt++;
                    i+=2;
                }
                else
                {
                    cnt+=2;
                    i++;
                }
            }
            else if (ch[i+1]=='-')
            {
                cnt++;
                i++;
            }
            else
            {
                cnt++;
            }
        }
        else if(ch[i]=='l' && i!=strlen(ch)-1) //l
        {
            if(ch[i+1]=='j')
            {
                cnt++;
                i++;
            }
            else
            {
                cnt++;
            }
        }
        else if(ch[i]=='n' && i!=strlen(ch)-1) //n
        {
            if(ch[i+1]=='j')
            {
                cnt++;
                i++;
            }
            else
            {
                cnt++;
            }
        }
        else if(ch[i]=='s' && i!=strlen(ch)-1)
        {
            if(ch[i+1]=='=')
            {
                cnt++;
                i++;
            }
            else
            {
                cnt++;
            }
        }
        else if(ch[i]=='z' && i!=strlen(ch)-1)
        {
            if(ch[i+1]=='=')
            {
                cnt++;
                i++;
            }
            else
            {
                cnt++;
            }
        }
        else
        {
            cnt++;
        }
    }
    printf("%d",cnt);
}