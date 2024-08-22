"""
ans=n인 이유
기본적인 모든 친구들은 적어도 1의 시간만큼 있어야함
거기서 서로 친구들끼리의 구간을 구하고
거기서 제일 작은 구간만 포함하는것이 그리디의 목적
n-k는 성냥을 사용해 줄일 수 없는 남은 간격의 수를 의미하며, 
이 간격들을 모두 더해주어 최종적으로 난로가 켜져 있는 최소 시간을 구합니다.
"""
n,k=map(int,input().split())
arr=[]
for i in range(n):
    a=int(input())
    arr.append(a)

start=arr[0]+1
narr=[]
for i in range(1,n):
    narr.append(arr[i]-start)
    start=arr[i]+1
narr.sort()
ans=n
for i in range(n-k):
    ans+=narr[i]

print(ans)