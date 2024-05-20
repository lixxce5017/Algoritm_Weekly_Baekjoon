s= list(input())
m=list(input())
start=0
cnt=0
while start<len(s):
    #print(s[start:start+len(m)])
    if m==s[start:start+len(m)]:
        cnt+=1
        start+=len(m)
    else:
        start+=1


print(cnt)