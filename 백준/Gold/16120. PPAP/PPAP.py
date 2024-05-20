import sys
from collections import deque
import copy
s=input()
stack=[]

for i in s:
    stack.append(i)
    if stack[-4:]==['P','P','A','P']:

        for j in range(4):
            stack.pop()
        stack.append("P")

if stack ==['P','P,','A','P'] or stack == ['P']:
    print("PPAP")
else:
    print("NP")