#노드의 깊이가 1보다 커야지만 리턴 값 넘겨야함
n=map(int,input())
s=input()
start="()()"
cnt=0
stack=[]
for i in s:
    if i=='(':
        if len(stack)==0:
            stack.append("(")
        elif stack[-1]==')':
            stack.pop()
        else:
            stack.append("(")

    elif i==')':
        if len(stack)==0:
            stack.append(")")
        elif stack[-1]=='(':
            stack.pop()
        else:
            stack.append(")")
    cnt=max(len(stack),cnt)

if len(stack)>=1:
    print(-1)

else:
    print(cnt)