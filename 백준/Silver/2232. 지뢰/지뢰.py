n=int(input())
arr=[]
ans=[]
for i in range(n):
    arr.append(int(input()))
if n==1:
    print(1)
    exit()

for i in range(n):
    if i==n-1 and arr[i]>=arr[i-1]:
        ans.append(i)
    if i==0 and arr[i]>=arr[i+1]:
        ans.append(i)
    elif i!=n-1 and arr[i+1]<=arr[i] and arr[i]>=arr[i-1]:
        ans.append(i)
ans.sort()
for i in ans:
    print(i+1,end='\n')