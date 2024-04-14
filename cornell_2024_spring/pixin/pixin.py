n, m = map(int, input().split())

blocks = []

for i in range(m):
    s, e = map(int, input().split())
    blocks.append([s, e])

blocks.sort(key=lambda a: a[0])


sum_seen = 0

current_block = [0, 0]
for block in blocks:
    if block[0] > current_block[1]:
        sum_seen += block[0] - current_block[1]
        current_block = block
    else:
        current_block[1] = max(current_block[1], block[1])
sum_seen += n - current_block[1]
# print(current_block)
print(sum_seen)
