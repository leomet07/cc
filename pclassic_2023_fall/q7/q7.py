n = int(input())

heights = list(map(int, input().split()))

# def how_many_hit(heights: "list[int]" ):
#     m = 0
#     hit = 0
#     for i in range(len(heights)):
#         c = heights[i]

#         if c > m:
#             hit += 1
#         m = max(m, c)

#     return hit



# Need to pre


def find_index(heights: "list[int]"):
    col_sums = [0] * len(heights)

    for i in range(len(heights)):
        # howmany = how_many_hit_dict(heights[0 : i] + heights[i + 1 :])
        # print(howmany)
        m = 0
        for i in range(len(heights)):
            c = heights[i]

            if c > m:
                col_sums[i] = col_sums[i] + 1
            m = max(m, c)

    print("Col sums: ", col_sums)

    min_value = min(col_sums)
    min_index = col_sums.index(min_value)

    return min_index


print(find_index(heights))
