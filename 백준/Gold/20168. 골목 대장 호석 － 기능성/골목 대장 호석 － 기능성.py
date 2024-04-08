import sys

N,M,A,B,C=map(int,input().split())

board=[[] for _ in range(N+1)]
visitieid=[[False] for _ in range(N+1)]
answer=sys.maxsize

def dfs(start, end, cost,maxS):
    visitieid[start]=True
    global  answer
    if start==end:
        answer =min(answer,maxS)
        return
    for item in board[start]:
        if visitieid[item[0]]==True:
            continue
        if item[1]>cost:
            continue
        visitieid[item[0]]=True
        dfs(item[0],end,cost-item[1],max(maxS,item[1]))
        visitieid[item[0]]=False



for _ in range(M):
    n1,n2,cost=map(int,input().split())
    board[n1].append((n2,cost))
    board[n2].append((n1,cost))

dfs(A,B,C,0)

if answer==sys.maxsize:
    answer-1
print(answer)