import heapq
n=int(input())
arr=[]
for _ in range(n):
    a,b=map(int,(input()).split())
    arr.append((a,b))

arr.sort(key=lambda x:x[0])

queue=[]
cnt=1
first=arr[0][0]
heapq.heappush(queue,arr[0][1])

#print(arr)
for i in range(1,len(arr)):
    if arr[i][0] >=queue[0]:
        first=arr[i][0]
        heapq.heappop(queue)
        heapq.heappush(queue, arr[i][1])
    else:
        heapq.heappush(queue, arr[i][1])
        first = arr[i][0]


print(len(queue))