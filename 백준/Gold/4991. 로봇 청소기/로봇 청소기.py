#bfs 하나로 배열 return 하면 간단
#공통점은 둘 다*만나야한다.
from collections import deque
from itertools import permutations
per_visited=[0]*11
#i+1 idx해야지 조합
#visitied 안걸면 중복조합
#0부터 가면 순열
#visitied 안걸면 중복순열
#까먹지 말자~
def dfs(p,idx,cnt,permutation_arr):
    global per_visited
    global ans
    if cnt==p:
        #print(permutation_arr)
        ans_dist = 0
        ans_dist += dust_start_dist[permutation_arr[0]]
        start = permutation_arr[0]
        for i in range(1,len(permutation_arr)):
                to_end=permutation_arr[i]
         #       print(start,to_end)
                ans_dist+=dust_dis[start][to_end]
                start=to_end
        ans = min(ans_dist, ans)
        #print(ans_dist)

        return
    for i in range(0,p):
            if per_visited[i]==0:
                permutation_arr.append(i)
                per_visited[i]=1
                dfs(p,0,cnt+1,permutation_arr)
                per_visited[i]=0
                permutation_arr.pop()

def bfs(x, y):
    q = deque()
    visitieid = [[0]*m for _ in range(n)]
    q.append([x, y])
    visitieid[x][y] = 1
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m:
                if Map[nx][ny] != 'x' and not visitieid[nx][ny]:
                    visitieid[nx][ny] = visitieid[x][y] + 1
                    q.append([nx, ny])
    return visitieid

while 1:

    m,n=map(int,input().split())
    if m==0 and n==0:
        break
    Map=[list(input().strip()) for _ in range(n)]
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    N_dust=[]
    sx,sy=0,0
    for i in range(n):
        for j in range(m):
            if Map[i][j]=='*':
                N_dust.append((i,j))
            elif Map[i][j]=='o':
                sx,sy=i,j

    #혹시라도 못가는 경로가 있는지 검사
    #못가면 바로 -1 출력하고 종료
    visit_Arr=bfs(sx,sy)
    #print(visit_Arr)
    dust_start_dist=[]
    flag=False
    #print(N_dust)
    for x,y in N_dust:
        if visit_Arr[x][y]==0:
            flag=True
        #출발에서 각 먼지의 최단거리 값 기록 리스트
        dust_start_dist.append(visit_Arr[x][y]-1)

    #print(dust_start_dist)
    if flag:
        print(-1)
        continue
    #모든 먼지에서 모든 다른먼지로 가는 경로
    dust_dis=[[0]*len(N_dust) for _ in range(len(N_dust))]
    #print(dust_dis)
    #마지막은 어차피 0 돌릴 핋요 없고 인덱스 레인지 오버 남
    for i in range(len(N_dust)-1):
        visit_Arr2=bfs(N_dust[i][0],N_dust[i][1])
        #print(visit_Arr)
        for j in range(i+1,len(N_dust)):
            #bfs가 1로 시작해서 다 1빼고 시작해야함
            dust_dis[i][j]=visit_Arr2[N_dust[j][0]][N_dust[j][1]]-1
            dust_dis[j][i] = visit_Arr2[N_dust[j][0]][N_dust[j][1]] - 1
    #틀리면 바꾸자
    ans=999999
    #print(dust_dis)
    #print(dust_start_dist)
    permutation_arr=[]
    dfs(len(N_dust), 0, 0, permutation_arr)
    print(ans)
