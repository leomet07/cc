a , b = list(map(int, input().split()))

n = int(input())
vslashes = list(map(int, input().split()))
m = int(input())
hslashes = list(map(int, input().split()))

maxa = 0

vslashes.insert(0, 0)
hslashes.insert(0, 0)
vslashes.append(a)
hslashes.append(b)

for i in range(1, len(vslashes)):
    dist = abs(vslashes[i] - vslashes[i - 1])

    for j in range(1, len(hslashes)):
        hdist = abs(hslashes[j] - hslashes[j - 1])
        maxa = max(hdist * dist, maxa)

print(maxa)