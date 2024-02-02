
import sys
input = sys.stdin.readline

# recursion 100000으로 늘리기
sys.setrecursionlimit(1000000)



x = int(input())

mem = {1: 0}

def dp(x):
    if x in mem:
        return mem[x]

    if x % 3 == 0 and x % 2 == 0:
        # mem[x] = min(dp(x//3), dp(x//2), dp(x-1)) + 1
        mem[x] = min(dp(x//3), dp(x//2)) + 1
    elif x % 3 == 0:
        mem[x] = min(dp(x//3), dp(x-1)) + 1
    elif x % 2 == 0:  
        mem[x] = min(dp(x//2), dp(x-1)) + 1
    else:
        mem[x] = dp(x-1) + 1

    return mem[x]

print(dp(x))
