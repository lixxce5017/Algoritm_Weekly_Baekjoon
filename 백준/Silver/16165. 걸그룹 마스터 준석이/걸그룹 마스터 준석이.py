import sys

n,m= map(int,input().split())
dic=dict()
for i in range(n):
    s=input()
    num=int(input())
    list=[]
    for j in range(num):
        idol=input()
        list.append(idol)
        dic[s]=list


for j in range(m):

    name =input()
    query = int(input())
    if query==1:
        for key,val in dic.items():
            if name in val:
                print(key)
    else:
        print('\n'.join(sorted(dic[name])))