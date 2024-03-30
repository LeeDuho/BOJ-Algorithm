import sys
import heapq
input = sys.stdin.readline

n, m, x = map(int, input().split()) # N학생, M 도로

graph = [[] for _ in range(n+1)]
graph_reverse = [[] for _ in range(n+1)]

for _ in range(m):
  a, b, t = map(int, input().split())
  graph[a].append((b,t))
  graph_reverse[b].append((a,t))

# x에서 각 지점까지 최단거리, 다익스트라

def dijkstra(x,g):
  global n
  dist = [987654321] * (n+1)

  heap = []
  
  # for nnode,ncost in g[x]:
  #   dist[nnode] = ncost
  #   heapq.heappush(heap,(ncost,nnode))

  heapq.heappush(heap,(0,x))
  dist[x]=0
  
  while heap:
    cost, node = heapq.heappop(heap)

    if cost > dist[node]:
      continue

    for nnode,ncost in g[node]:
      if dist[nnode] > cost+ncost:
        dist[nnode] = cost+ncost
        heapq.heappush(heap,(cost+ncost, nnode))

  return dist

dist1 = dijkstra(x, graph)
dist2 = dijkstra(x, graph_reverse)

dist_sum = [0] * (n+1)
for i in range(n+1):
  dist_sum[i] = dist1[i] + dist2[i]
dist_sum[0] = -1

print(max(dist_sum))












