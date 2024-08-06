# 2번 방법
import sys
import heapq
n=int(input())
stack=[]
ans=[0]*n
arr=list(map(int,input().split()))
for i in range(n):
    num=arr[i]
    while len(stack)!=0 and stack[-1][0]<num:
        stack.pop()
    if len(stack)==0:
        ans[i]=0
    else:
        ans[i]=stack[-1][1]
    stack.append((num,i+1))

for i in ans:
    print(i,end=' ')

