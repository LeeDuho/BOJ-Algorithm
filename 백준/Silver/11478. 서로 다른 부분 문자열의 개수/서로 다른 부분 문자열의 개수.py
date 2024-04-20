import sys

read = sys.stdin.readline

str = read().rstrip()
subs = set()

for i in range(len(str)):
  for j in range(i, len(str)):
    tmp = str[i:j+1]
    subs.add(tmp)
print(len(subs))