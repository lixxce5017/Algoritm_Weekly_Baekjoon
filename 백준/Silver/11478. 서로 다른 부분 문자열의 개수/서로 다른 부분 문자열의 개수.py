
lis=input()
ss=set()
for i in range(len(lis)):
    for j in range(0,i+1):
        ss.add(lis[j:i+1])

print(len(ss))