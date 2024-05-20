import sys
from collections import deque
import copy
sys.setrecursionlimit(100000)




s=list(input())
t=list(input())

#s에다가 a,b연산만 해서 t가 되는가? 백트래킹으로

def dfs(nowS):
   global result

   if len(nowS)==len(s):
        if s==nowS:
          result=1
        return

   if nowS[-1] =='A':
       nowS.pop()
       dfs(nowS)
       nowS.append('A')
   if nowS[0]== 'B':
       nowS.reverse()
       nowS.pop()
       dfs(nowS)
       nowS.append('B')
       nowS.reverse()

result=0
dfs(t)
print(result)
