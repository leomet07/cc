n = int(input())

heights = list(map(int, input().split()))

def how_many_hit(heights: "list[int]" ):
    m = 0
    hit = 0
    for i in range(len(heights)):
        c = heights[i]

        if c > m:
            hit += 1
        m = max(m, c)

    return hit
        

def find_index(heights: "list[int]"):
    max_value = 0
    max_index = 0
    for i in range(len(heights)):
        v = heights[i]
        # print("Popped list: ",  heights[0 : i] + heights[i + 1 :])
        howmany = how_many_hit(heights[0 : i] + heights[i + 1 :])
        # print("How many: ", howmany)
        if howmany > max_value:
            max_value = howmany
            max_index = i

    return max_index


print(find_index(heights) + 1)
