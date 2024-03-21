import sys
sys.setrecursionlimit(10000000)

n, m = map(int, sys.stdin.readline().split())

graph = [[] for _ in range(n+1)]

for _ in range(m):
  u, v = map(int,sys.stdin.readline().split())
  graph[u].append(v)
  graph[v].append(u)

visited = [False]*(n+1)
res = 0

def dfs(i):
  # for j in range(len(graph[i]))
  for j in graph[i]:
    if visited[j] == False:
      visited[j] = True
      dfs(j)

for i in range(1,n+1):
  if visited[i] == False:
    res += 1
    visited[i] = True
    dfs(i)

print(res)
