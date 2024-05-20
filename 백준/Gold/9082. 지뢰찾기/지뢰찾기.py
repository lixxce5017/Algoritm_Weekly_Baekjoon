from collections import deque

t=int(input())

while t:
    n = int(input())
    num = list(map(int, input().rstrip()))
    mine = input().strip()
    result = 0
    for i in range (n):
        if i==0 and num[i] !=0 and num[i+1] !=0:
            num[i]-=1
            num[i+1]-=1
            result+=1
        elif i==n -1 and num[i] != 0 and num[i-1]!=0:
            num[i] -= 1
            num[i -1] -= 1
            result += 1
        elif 1<=i<=n-2 and num[i-1]!=0 and num[i]!=0and num[i+1]!=0:
            num[i] -= 1
            num[i - 1] -= 1
            num[i+1]-=1
            result += 1

    print(result)
    t=t-1


