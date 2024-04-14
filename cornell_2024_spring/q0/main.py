n = int(input())

words = input().split()

c = 0
for word in words:
    word = word.lower()
    if word.startswith("c"):
        c += 1

print(c)
