#노드의 깊이가 1보다 커야지만 리턴 값 넘겨야함
s=input()

#100만이니 라인스위핑이다.
#더 적은 숫자의 숫자로 뒤집어 보는건 어떨까요?

zcnt=0
onecnt=0
for i in s:
    if i=="0":
        onecnt+=1
    else:
        zcnt+=1

res=0
if zcnt>=onecnt:
    res=0
else:
    res=1
cnt=0
for i in range(len(s)):
    if int(s[i])==res and int(s[i-1])!=res:
        cnt+=1


print(cnt)