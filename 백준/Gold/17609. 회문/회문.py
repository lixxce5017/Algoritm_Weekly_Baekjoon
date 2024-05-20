import math
import sys
from collections import deque
from itertools import combinations
t=int(input())
while t:
    s=str(sys.stdin.readline().strip())
    start=0
    end=len(s)-1
    palen=0
    #회문판별
    while start<=end:
        if s[start] ==s[end]:
            start += 1
            end -= 1

        else:
            if start<=end-1:
                tmp=s[:end] +s[end+1:]
                if tmp[:]==tmp[::-1]:
                    print(1)
                    palen = 1
                    break

            if start+1<=end:
                tmp=s[:start] +s[start+1:]
                if tmp[:]==tmp[::-1]:
                    print(1)
                    palen=1
                    break
            palen=2
            print(2)
            break

    if palen==0:
        print(0)


    t=t-1

