import sys
from collections import deque
input=sys.stdin.readline
arr=list(input().rstrip())
ans=[]
for i in range(len(arr)):
    for j in range(i+1,len(arr)-1):
        if i==j:
            continue
        temp1=[]
        temp2=[]
        temp3=[]
        for q in range(i+1):
            temp1.append(arr[q])
        for q in range(i+1,j+1):
            temp2.append(arr[q])
        for q in range(j+1,len(arr)):
            temp3.append(arr[q])
        temp1.reverse()
        temp2.reverse()
        temp3.reverse()
        tmpe=temp1+temp2+temp3
        ans.append(tmpe)
ans.sort()
for i in ans[0]:
    print(i,end='')