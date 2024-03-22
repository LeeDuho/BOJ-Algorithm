import sys
input = sys.stdin.readline
from collections import deque

n, m = map(int, input().split())

road = []
visited = [[False]*m for _ in range(n)]

for i in range(n):
  road.append(list(map(int,input().split())))
  for j in range(m):
    if road[i][j] == 2:
      start_n = i
      start_m = j

queue = deque()

queue.append((start_n,start_m,0))
visited[start_n][start_m] = True

nx = [0,1,0,-1]
ny = [1,0,-1,0]

while(queue):
  x, y, cnt = queue.popleft()
  road[x][y] = cnt
  for i in range(4):
    if 0 <= x+nx[i] < n and 0 <= y+ny[i] < m and visited[x+nx[i]][y+ny[i]] == False and road[x+nx[i]][y+ny[i]] != 0:
      visited[x+nx[i]][y+ny[i]] = True
      queue.append((x+nx[i],y+ny[i],cnt+1))


for i in range(n):
  for j in range(m):
    if(visited[i][j]==False and road[i][j]==1):
      road[i][j] = -1
    print(road[i][j],end=' ')
  print()
