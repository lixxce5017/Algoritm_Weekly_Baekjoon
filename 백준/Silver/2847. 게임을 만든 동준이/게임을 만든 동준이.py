import heapq
n=int(input())
arr=[]
for i in range(n):
    c=int(input())
    arr.append(c)
cnt=0

for i in range(len(arr)-2,-1,-1):
    while arr[i+1]<=arr[i]:
        arr[i]=arr[i]-1
        cnt+=1



print(cnt)
