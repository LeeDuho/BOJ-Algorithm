a,b = input().split()
li = list(map(int,(a[::-1],b[::-1])))
print(max(li))