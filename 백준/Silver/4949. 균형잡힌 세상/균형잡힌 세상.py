import sys
from collections import deque

while True:
    a=input()
    stack = []
    if a == ".":
        break
    for i in a:
            #Help( I[m being held prisoner in a fortune cookie factory)].
        if i=='(':
            stack.append('(')
        elif i=='[':
            stack.append('[')
        elif i==')':
            if len(stack)>=1 and stack[-1] =='(':
                stack.pop()
            else:
                stack.append(')')
                break

        elif i == ']':
            if len(stack)>=1 and stack[-1] =='[':
                stack.pop()
            else:
                stack.append(']')
                break

    if len(stack)>=1:
        print("no")
    else:
        print("yes")