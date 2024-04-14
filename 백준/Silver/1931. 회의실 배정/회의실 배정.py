n=int(input())
arr=[]
for _ in range(n):
    a,b=map(int,(input()).split())
    arr.append((a,b))

arr.sort(key=lambda x:(x[1],x[0]))


cnt=1
first=arr[0][0]
second=arr[0][1]
#print(arr)
for i in range(1,len(arr)):
    if second <=arr[i][0]:
        cnt+=1
        first=arr[i][0]
        second=arr[i][1]

print(cnt)