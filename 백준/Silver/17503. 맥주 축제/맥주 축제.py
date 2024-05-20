import sys
import heapq
day, sum_taste, kind = map(int,input().split())
lis = []
pq = []
heapq.heapify(pq)
for _ in range(kind):
    taste, alch = map(int,sys.stdin.readline().split())
    lis.append((taste,alch))
lis.sort(key=lambda x: (x[1],x[0]))
find = False
now_alchol = 0
s = 0
for i in range(kind):
    heapq.heappush(pq,lis[i][0])
    s += lis[i][0]
    now_alchol = lis[i][1]
    if len(pq) == day:
        if s >= sum_taste:
            find = True
            print(now_alchol)
            break
        else:
            s -= heapq.heappop(pq)
if not find:
    print(-1)