import math
import sys
from collections import deque
from itertools import combinations


str = sys.stdin.readline().strip()

def palindrome(s):
   if len(s)==1:
       return True
   #짝수 홀 수 구분
   perfiex =s[:len(s)//2]
   suffix = s[len(s)//2:] if len(s)%2==0 else s[len(s)//2+1]
   if s==s[::-1] and perfiex ==perfiex[::-1] and suffix==suffix[::-1]:
       return palindrome(perfiex) and palindrome(suffix)
   else:
       return False

if palindrome(str)==True:
    print("AKARAKA")
else:
    print("IPSELENTI")