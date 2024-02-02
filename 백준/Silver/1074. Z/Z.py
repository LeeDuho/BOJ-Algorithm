n, r, c = map(int, input().split())

first_num = 0
now_n = n
while(True):
    if now_n == 0:
        break
    now_n -= 1
    
    if r < 2**now_n and c < 2**now_n:
        first_num += 0
    elif r < 2**now_n and c >= 2**now_n:
        first_num += 2**now_n * 2**now_n
        c -= 2**now_n
    elif r >= 2**now_n and c < 2**now_n:
        first_num += 2**now_n * 2**now_n * 2
        r -= 2**now_n
    else:
        first_num += 2**now_n * 2**now_n * 3
        r -= 2**now_n
        c -= 2**now_n

print(first_num)