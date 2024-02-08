import sys
input = sys.stdin.readline

n, m = map(int, input().split())

no_listen = set()
no_listen_no_see = set()

for i in range(n):
  name = input().strip()
  no_listen.add(name)

for i in range(m):
  name = input().strip()
  if name in no_listen:
    no_listen_no_see.add(name)

no_listen_no_see = list(no_listen_no_see)
no_listen_no_see.sort()

print(len(no_listen_no_see))
for name in no_listen_no_see:
  print(name)
  