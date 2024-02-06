import sys
input = sys.stdin.readline

n, k = map(int, input().split())

queue = []
visited = [0] * 100001
queue.append((n, 0))
visited[n] = 1

while queue:
    now, time = queue.pop(0)
    if now == k:
        print(time)
        break
    if now-1 >= 0 and not visited[now-1]:
        queue.append((now-1, time+1))
        visited[now-1] = 1
    if now+1 <= 100000 and not visited[now+1]:
        queue.append((now+1, time+1))
        visited[now+1] = 1
    if now*2 <= 100000 and not visited[now*2]:
        queue.append((now*2, time+1))
        visited[now*2] = 1
