n=int(input())

arr = [-1] + list(map(int, input().split()))
t=int(input())

for i in range(t):
    sex,num=map(int,input().split())

    #배수 스위치 키고 끄기
    if sex==1:
        for k in range(num,n+1,num):
            if arr[k]==1:
                arr[k] = 0
            else:
                arr[k] = 1
    else:
        #좌우가 같으면 계속
        start= num-1
        end=num+1
        while 1:
            if start >= 1 and end <= n:
                if arr[start]!=arr[end]:
                    break
                else:
                    if arr[start] == 1:
                        arr[start] = 0
                    else:
                        arr[start] = 1
                    if arr[end] == 1:
                        arr[end] = 0
                    else:
                        arr[end] = 1
                    if start <= 1 or end >= n:
                        break
                    start-=1
                    end+=1
            else:
                break
        if arr[num]==1:
            arr[num]=0
        else:
            arr[num]=1


for i in range(1,n+1):
    print(arr[i],end=" ")
    if i%20==0:
        print()