n , k = list(map(int, input().split()))
ogk = k

rings =  list(map(int, input().split()))

for i in range(k):
    rings.append(rings[-1])


m = 0
curr = 0

for i in range(0, k):
    curr += rings[i]
    m = max(m, curr + rings[i] * (ogk - i - 1))

curr = 0

for i in range(1, k + 1):
    curr += rings[i]
    m = max(m, curr + rings[i] * (ogk - i))

print(m)