import  sys
input=sys.stdin.readline
def union(a,b):
    a=find(a)
    b=find(b)
    if a<b:
        uf[b]=a
    else:
        uf[a]=b

def find(a):
    if a==uf[a]:
        return a
    else:
        return find(uf[a])

n=int(input())
uf=list(range(n+1))
for i in range(1,n+1):
    uf[i]=i

for i in range(n-2):
    a,b=map(int,input().split())
    union(a,b)

target_node=find(1)

for i in range(2,n+1):
    if find(target_node)!=find(i):
        print(target_node,i)
        break
