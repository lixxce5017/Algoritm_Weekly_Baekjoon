import copy,sys
from itertools import product
#재귀 얼마만큼 늘려야하는지 디버깅할때 조심
n=int(input())
orign=[list(map(int,input().split()))for _ in range(n)]

res=0


def up(MAP):
    for j in range(n):
        tempCnt=0
        for i in range(1,n):
            if MAP[i][j]!=0:
                temp=MAP[i][j]
                MAP[i][j]=0
                if MAP[tempCnt][j]==0:
                    MAP[tempCnt][j]=temp
                elif MAP[tempCnt][j]==temp:
                     MAP[tempCnt][j] *=2
                     tempCnt+=1
                else:
                    tempCnt+=1
                    MAP[tempCnt][j]= temp
    return MAP
def down(MAP):
    for j in range(n):
        tempCnt=n-1
        for i in range(n-1,-1,-1):
            if MAP[i][j]!=0:
                temp=MAP[i][j]
                MAP[i][j]=0
                if MAP[tempCnt][j]==0:
                    MAP[tempCnt][j]=temp
                elif MAP[tempCnt][j]==temp:
                    MAP[tempCnt][j]*=2
                    tempCnt-=1
                else:
                    tempCnt-=1
                    MAP[tempCnt][j]=temp
    return MAP                        

def right(MAP):
    for i in range(n):
        tempCnt=n-1
        for j in range(n-1,-1,-1):
            if MAP[i][j]!=0:
                temp=MAP[i][j]
                MAP[i][j]=0
                if MAP[i][tempCnt]==0:
                    MAP[i][tempCnt]=temp
                elif MAP[i][tempCnt]==temp:
                        MAP[i][tempCnt] *=2
                        tempCnt-=1
                else:
                    tempCnt-=1
                    MAP[i][tempCnt]= temp
    return MAP    

def left(MAP):
    for i in range(n):
        tempCnt=0
        for j in range(1,n):
            if MAP[i][j]!=0:
                temp=MAP[i][j]
                MAP[i][j]=0
                if MAP[i][tempCnt]==0:
                    MAP[i][tempCnt]=temp
                elif MAP[i][tempCnt]==temp:
                     MAP[i][tempCnt] *=2
                     tempCnt+=1
                else:
                    tempCnt+=1
                    MAP[i][tempCnt]= temp
    return MAP
    

    
def dfs(num,map):
    global res
    if num==5:
        for i in range(n):
            for j in range(n):
                if map[i][j]>res:
                    res=map[i][j]
        
        return
    
    for i in range(4):
        copy_ar=copy.deepcopy(map)
        if i==0:
            dfs(num+1,left(copy_ar))
        elif i==1:
            dfs(num+1,right(copy_ar))
        elif i==2:
            dfs(num+1,up(copy_ar))
        elif i==3:
            dfs(num+1,down(copy_ar))
        

dfs(0,orign)
print(res)