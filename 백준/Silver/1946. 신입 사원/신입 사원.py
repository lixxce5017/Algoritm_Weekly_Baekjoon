n=int(input())
while n:
    k=int(input())
    arr=[]
    for i in range(k):
        a,b=map(int,input().split())
        arr.append((a,b))

    arr.sort()
    cnt=1
    max_=arr[0][1]
    for i in range(1,k):
        if  max_ >arr[i][1]:
            cnt+=1
            max_= arr[i][1]
    print(cnt)

    n-=1