import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000000)

v = int(input())

tree = [[] for _ in range(v+1)]

# for i in range(1,v+1):
#   temp = list(map(int,input().split()))
#   for j in range(1, len(temp)-1,2):
#     tree[i].append([temp[j],temp[j+1]])

for _ in range(v):
    node = list(map(int, input().split()))[:-1]
    for i in range(1, len(node)//2 + 1):
        tree[node[0]].append([node[i*2 - 1], node[i*2]])

def dfs(i,total_len):

  for node in tree[i]:
    if visited[node[0]] == -1:
      visited[node[0]] = total_len + node[1]
      dfs(node[0],total_len + node[1])
      

visited = [-1] * (v+1)
visited[1] = 0
dfs(1,0)

# temp = 1
# for i in range(1, v+1):
#   if visited[i] > visited[temp]:
#     temp = i

temp = visited.index(max(visited))


visited = [-1] * (v+1)
visited[temp] = 0
dfs(temp,0)

res = max(visited)
print(res)

