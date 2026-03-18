arr=[0]*11
n=list(input())
for i in n:
    if i=='6' or i=='9':
        arr[10]+=1
    else:
        arr[ord(i)-ord('0')]+=1
if arr[10]%2==0:
    arr[10]=arr[10]//2
else:
      arr[10]=arr[10]//2+1
print(max(arr))