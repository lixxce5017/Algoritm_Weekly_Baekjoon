import sys

n,m=map(int,(input().split()))
num=dict()
target=[]
for i in range(n):
    word=sys.stdin.readline().strip()
    num[word]=True

cnt=0
for i in range(m):
    t=input()
    if t in num.keys():
            cnt+=1

print(cnt)
