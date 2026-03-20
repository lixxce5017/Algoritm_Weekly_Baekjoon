arr=[0]*26
plen=list(input())
for i in plen:
    arr[ord(i)-ord('A')]+=1

cnt=0
for i in arr:
    if i%2==1:
        cnt+=1
if cnt>=2:
    print("I'm Sorry Hansoo")
else:
    qwe=''
    alphaarr=[]
    for i in range(len(arr)):
        if arr[i]%2==1:
            qwe=chr(i+ord('A'))
            arr[i]-=1
        if arr[i] >= 1:
            alphaarr.append([i, arr[i]])

    end=len(plen)-1
    start=0
    ans=['']*len(plen)
    alphacnt=0
    while start<end:
        ans[start]=chr(alphaarr[alphacnt][0]+ord('A'))
        ans[end]=chr(alphaarr[alphacnt][0]+ord('A'))
        alphaarr[alphacnt][1]-=2
        if alphaarr[alphacnt][1]<=0:
            alphacnt+=1
        start+=1
        end-=1
    if len(plen)%2==0:
        print("".join(ans))
    else:
        ans[(len(plen)//2)]=qwe
        print("".join(ans))