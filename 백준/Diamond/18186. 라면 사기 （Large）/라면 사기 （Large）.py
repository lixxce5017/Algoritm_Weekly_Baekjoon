from collections import deque

n,b,c =map(int,(input().split()))

arr=list(map(int,input().split()))+[0,0]
cnt=0
ans=0
def buy1(num):
    global ans
    ans += (b* arr[num])
    arr[num] -= 1

def buy2(num):
    global ans
    m= min(arr[num:num+2])
    arr[num]-=m
    arr[num+1]-=m
    ans +=((b+c)*m)

def buy3(num):
    global ans
    m=min(arr[num:num+3])
    arr[num] -=m
    arr[num+1]-=m
    arr[num+2] -=m
    ans+=((b+2*c)*m)

if b<c:
        for i in range(len(arr)):
            ans+=arr[i] * b

        print(ans)
        exit(0)


for i in range(n):
    #2개 사는 경우
        if arr[i+1]>arr[i+2]:
            m=min(arr[i],arr[i+1]-arr[i+2])
            #두개 구매
            arr[i]-=m
            arr[i+1]-=m
            ans+=(b+c)*m

            buy3(i)
            buy1(i)
        else:

            buy3(i)
            buy2(i)
            buy1(i)





print(ans)