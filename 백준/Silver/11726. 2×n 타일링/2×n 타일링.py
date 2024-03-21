import sys

n = int(input())

res = [0] * 1009

res[1] = 1
res[2] = 2

for i in range(3, 1001):
  # res[i+1] += (res[i] + 1)
  # res[i+2] += (res[i] + 1)
  res[i] = res[i-1] + res[i-2]

print(res[n]%10007)

