n=int(input())

arr= [0 for i in range(n)]
for i in range(n):
    a=int(input())
    arr[i]=a
arr.sort()
t=0
for i in range(n):
    t+=abs(arr[i]-(i+1))

print(t)
