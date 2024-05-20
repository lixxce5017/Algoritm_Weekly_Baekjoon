import sys

n = int(input())
weight, height = [0] * n, [0] * n
for i in range(n):
  weight[i], height[i] = map(int, sys.stdin.readline().split())

for i in range(n):
  count = 1
  for j in range(n):
    if weight[i] < weight[j] and height[i] < height[j]:
      count += 1
  print(count, end=" ")