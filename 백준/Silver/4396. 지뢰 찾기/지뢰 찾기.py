from collections import deque
n=int(input())
boomer=[list(input())for _ in range(n)]
Open_Map=[list(input()) for _ in range(n)]
#왼쪽 대각선,상 오른쪽 대각선,우,우하대각,하,죄하 대각,좌

dir=[(-1,-1),(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1)]
Map=[[0]*n for _ in range(n)]
tureth=0
for i in range(n):
    for j in range(n):
        if Open_Map[i][j]=='x':
            if boomer[i][j]=='.':
                for k,q in dir:
                    nx=i+k
                    ny=j+q
                    if nx>=0 and ny>=0 and nx<n and ny <n:
                        if boomer[nx][ny]=='*':
                            Map[i][j]+=1
            else:
                Map[i][j]='*'
                tureth=1
        else:
            Map[i][j]='.'

for i in range(n):
  for j in range(n):
        if tureth==1 and boomer[i][j]=='*':
            print("*",end="")
        else:
            print(Map[i][j],end="")
  print()
