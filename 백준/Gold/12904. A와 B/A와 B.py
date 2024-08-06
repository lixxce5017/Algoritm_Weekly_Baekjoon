# 2번 방법
import sys
import heapq
a=list(input())
b=list(input())

while 1:
    if len(a)>len(b):
        print(0)
        break
    elif a==b:
        print(1)
        break
    if b[-1]=='A':
        b.pop()
    elif b[-1]=='B':
        b.pop()
        b.reverse()

