from collections import deque
import sys
input = sys.stdin.readline

n, k = map(int, input().split())

queue = deque()
queue.append(n)

visited = [0] * 100001

while queue:
    now = queue.popleft()
    if now == k:
        print(visited[now])
        break
    for next in (now-1, now+1, now*2):
        if 0 <= next < 100001 and not visited[next]:
            visited[next] = visited[now] + 1
            queue.append(next)

            