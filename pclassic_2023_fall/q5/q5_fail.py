n , k = list(map(int, input().split()))

rings =  list(map(int, input().split()))

# max_index = rings.index(max(rings))

# print(max_index)

maxsum = 0

for i in range(0, k):
    # csum = sum(rings[i: i + k ])
    staying = sum(rings[1: i + 1]) + (rings[i] * (k - i))
    # print("csum: ", csum)
    # print("csum: ", csum)
    print("staying: ", staying)
    maxsum = max(max(maxsum, staying), staying + rings[0] - rings[i])

print(maxsum)