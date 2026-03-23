n=int(input())
target=list(input())
arr=[]
for i in range(n-1):
    tmp=list(input())
    arr.append(tmp)

alpha=[0]*26
for val in target:
    alpha[ord(val)-ord('A')]+=1

ans=0

for i in range(n-1):
    alpha2=[0]*26
    for j in arr[i]:
        alpha2[ord(j)-ord('A')]+=1

    flagcnt=0
    for j in range(26):
        flagcnt+=abs(alpha[j]-alpha2[j])

    # 길이 차이
    lendiff=abs(len(target)-len(arr[i]))

    # 같은 길이 → 교체 가능 (차이 0 또는 2)
    if lendiff==0 and (flagcnt==0 or flagcnt==2):
        ans+=1

    # 길이 1 차이 → 추가/삭제 가능 (차이 1)
    elif lendiff==1 and flagcnt==1:
        ans+=1

print(ans)
