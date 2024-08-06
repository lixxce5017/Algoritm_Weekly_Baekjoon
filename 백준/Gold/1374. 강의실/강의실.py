# 2번 방법
import sys
import heapq
n=int(input())
arr=[]
que=[]
for i in range(n):
    a,b,c=map(int,input().split())
    arr.append((b,c))
#빠르게 시작하는 기준
arr.sort(key=lambda x:x[0])

heapq.heappush(que,arr[0][1])
cnt=1
for i in range(1,n):
    if que[0]<=arr[i][0]:
        heapq.heappop(que)
        heapq.heappush(que, arr[i][1])
    else:
        heapq.heappush(que, arr[i][1])
    cnt=max(cnt,len(que))
print(cnt)