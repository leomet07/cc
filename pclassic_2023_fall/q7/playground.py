heights = [1, 8, 3, 2, 11, 9, 10]

def how_many_hit_dict(heights: "list[int]" ):
    m = 0
    hit = [0] * len(heights)
    for i in range(len(heights)):
        c = heights[i]

        if c > m:
            hit[i] = 1
        m = max(m, c)

    return hit

col_sums = [0] * len(heights)

print("DICT: ", how_many_hit_dict(heights))

for i in range(len(heights)):
    howmany = how_many_hit_dict(heights[0 : i] + heights[i + 1 :])
    print(howmany)
#     m = 0
#     for i in range(len(heights)):
#         c = heights[i]

#         if c > m:
#             col_sums[i] = col_sums[i] + 1
#         m = max(m, c)

# print(col_sums)

# min_value = min(col_sums)
# min_index = col_sums.index(min_value)

# print(min_index)