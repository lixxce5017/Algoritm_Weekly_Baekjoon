from collections import deque

n =int(input())
arr=[0 for _ in range(n+2)]
arr=list(map(int,input().split()))+[0,0]
cnt=0
ans=0
def buy1(num):
    global ans
    ans += 3 *arr[num]

def buy2(num):
    global ans
    m= min(arr[num:num+2])
    arr[num]-=m
    arr[num+1]-=m
    ans +=5*m

def buy3(num):
    global ans
    m=min(arr[num:num+3])
    arr[num] -=m
    arr[num+1]-=m
    arr[num+2] -=m
    ans+=7*m


for i in range(n):
    #2개 사는 경우
        if arr[i+1]>arr[i+2]:
            m=min(arr[i],arr[i+1]-arr[i+2])
            arr[i]-=m
            arr[i+1]-=m
            ans+=5 *m
            buy3(i)
            buy1(i)
        else:
            buy3(i)
            buy2(i)
            buy1(i)




print(ans)