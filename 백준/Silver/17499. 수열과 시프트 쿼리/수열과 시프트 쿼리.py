import sys

input = sys.stdin.readline

# n: 수열 길이, m: 쿼리 개수
n, m = map(int, input().split())
arr = list(map(int, input().split()))

idx = 0  # 현재 수열의 1번째 원소가 위치한 실제 배열의 인덱스

for i in range(m):
    brr = list(map(int, input().split()))

    if brr[0] == 1:
        # 1번 쿼리: i번째 원소에 x 더하기
        # 실제 인덱스 계산: (시작점 + (i-1)) % n
        arr[(idx + brr[1] - 1) % n] += brr[2]

    elif brr[0] == 2:
        # 2번 쿼리: 오른쪽으로 s칸 시프트 -> 시작점은 왼쪽으로 이동
        idx = (idx - brr[1]) % n

    elif brr[0] == 3:
        # 3번 쿼리: 왼쪽으로 s칸 시프트 -> 시작점은 오른쪽으로 이동
        idx = (idx + brr[1]) % n

# 최종 수열 출력
for i in range(n):
    print(arr[(idx + i) % n], end=' ')