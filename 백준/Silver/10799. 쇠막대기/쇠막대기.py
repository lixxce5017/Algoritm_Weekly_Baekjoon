import sys

s=input()
lis=[]
cnt=0
for i in range(len(s)):
    if s[i]=='(':
        lis.append('(')
    elif s[i]==')':
        if s[i-1]=='(':
            lis.pop()
            cnt+=len(lis)
        else:
            lis.pop()
            cnt+=1

print(cnt)
