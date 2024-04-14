start =  ord("A")
chars = list(map(str, range(0, 10))) + list(map(chr, list(range(start, start + 26))))

n = int(input())

s = ""

l = [1]

while True:
    l.append(len(l) * l[-1]) # Effecient factorial
    if l[-1] > n:
        break

l = l[1:len(l) - 1]

for i in range(len(l) -1, -1, -1):
    times_to_fit = n // l[i] # max times we can fit it
    s = s + chars[times_to_fit]
    n -= l[i] * times_to_fit

print(s)