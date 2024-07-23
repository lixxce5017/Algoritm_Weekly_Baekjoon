from copy import deepcopy
n=int(input())
Map=[0]*n
ans=0
# map[depth]=i의 의미는 map[i][j]에 퀸을 놓겠다는 의미
#  이걸로 가로 판별부터 상하 좌우까지 판별 가능
#대각선에 있는 친구들은 i-i 와 j-j가 같다는 성질을 이용
#현재까지 들어간 level(세로)를 기준으로 보는것
def chek(i):
    for i_2 in range(i):
        if Map[i_2]==Map[i] or (abs(Map[i_2]-Map[i])==abs(i-i_2)):
            return False
    return True

def dfs(i):
    global ans
    if i==n:
        ans+=1
        return


    for j in range(n):
        Map[i]=j
        if chek(i)==True:
            dfs(i+1)


dfs(0)
print(ans)