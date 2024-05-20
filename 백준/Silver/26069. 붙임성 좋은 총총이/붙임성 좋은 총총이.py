n=int(input())
a=[]
b=[]
cnt=1
#"무지개 댄스를 추지 않고 있던 사람이 무지개 댄스를 추고 있던 사람을 만나게 된다면,
# 만난 시점 이후로 무지개 댄스를 추게 된다."
arr={'ChongChong'}

for _ in range(n):
    A, B = input().split()
    if A in arr:
        arr.add(B)
    if B in arr:
        arr.add(A)

print(len(arr))