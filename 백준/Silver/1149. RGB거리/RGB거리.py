import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)

n = int(input())

costs = [list(map(int, input().split())) for _ in range(n)]


def BF(now):
  if now == n:
    return

  for i in range(3):
    temp_min = 987654321
    for j in range(3):
      if i != j:
        temp_min = min(temp_min,costs[now-1][j])
    costs[now][i] = costs[now][i] + temp_min

  BF(now+1)


BF(1)


min_res = min(costs[n-1][0],costs[n-1][1],costs[n-1][2])

print(min_res)

