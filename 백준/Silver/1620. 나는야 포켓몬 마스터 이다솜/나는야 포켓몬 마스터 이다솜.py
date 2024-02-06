import sys
input = sys.stdin.readline

n, m = map(int, input().split())
pokemons = {}
pokemons2 = {}
for i in range(1, n+1):
    pokemon = input().strip()
    pokemons[pokemon] = i
    pokemons2[i] = pokemon

for _ in range(m):
    question = input().strip()
    if question.isdigit():
        print(pokemons2[int(question)])
    else:
        print(pokemons[question])