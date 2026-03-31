import sys

# 찾고 싶은 문자열 입력 (예: 12340)
s = sys.stdin.readline().rstrip()

ans = 0  # 1, 2, 3... 계속 증가시킬 숫자
idx = 0  # 우리가 입력받은 문자열(s) 중 현재 찾고 있는 위치

while True:
    ans+=1
    temp=str(ans)
    for i in temp:
        if idx<len(s) and i==s[idx]:
            ans=int(temp)
            idx += 1
    if idx==len(s):
        break
print(ans)