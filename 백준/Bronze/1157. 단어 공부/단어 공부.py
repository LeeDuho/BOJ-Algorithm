sen = str(input()).upper()
sen_set = list(set(sen))
cnt = []

for i in sen_set:
    cnt.append(sen.count(i))

if cnt.count(max(cnt)) > 1:
    print("?")
else:
    print(sen_set[(cnt.index(max(cnt)))])
