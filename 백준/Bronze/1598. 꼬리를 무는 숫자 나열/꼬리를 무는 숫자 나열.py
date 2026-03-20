n,m = map(int,input().split())
row=abs(((n-1)//4-1) - ((m-1)//4-1))

col=abs((n-1)%4 - (m-1)%4)
print(row+col)
    