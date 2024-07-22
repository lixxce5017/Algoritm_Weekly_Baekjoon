import sys

n,m=map(int,sys.stdin.readline().split(' '))
dic=[]
talk=[]
#오름 차순
for i in range(n):
    a,b=sys.stdin.readline().split(' ')
    dic.append(int(b))
    talk.append(a)

for _ in range(m):
    new= int(sys.stdin.readline().rstrip())
    start=0
    end=n-1
    cnt=0
    while start<=end:
        mid= int((start+end)/2)
        if new>dic[mid]:
            start=mid+1
        else:
            cnt = mid
            end=mid-1
    print(talk[cnt])




