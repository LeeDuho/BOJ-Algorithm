n = int(input())

for i in range(n):
  results = input()

  score = 0
  sum = 0

  for result in results:
    if result == 'O':
      score += 1
      sum += score
    else:
      score = 0

  print(sum)