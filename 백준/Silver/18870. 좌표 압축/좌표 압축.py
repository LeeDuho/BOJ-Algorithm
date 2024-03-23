n = int(input())


input_coors = list(map(int,input().split()))
coors = list(set(input_coors))

coors.sort()

res = {}

for idx, coor in enumerate(coors):
  res[coor] = idx


for coor in input_coors:
  print(res[coor], end=' ')
