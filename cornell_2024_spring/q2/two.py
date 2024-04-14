a = [1, 2, 2, 3, 2, 3, 4, 3, 2, 3, 2, 3, 3, 4, 3, 4, 5, 4, 3, 4, 3, 4, 4, 4, 5, 4]


c = 0

text = input().lower()

for char in text:
    c += a[ord(char) - ord("a")]

print(c)
