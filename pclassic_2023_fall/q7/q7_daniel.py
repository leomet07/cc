n = int(input())

heights = list(map(int, input().split()))

max_index = 0
a = [1]

def isMore(num, nums):
    for i in nums:
        if num <= i:
            return False
    return True



for i in range(1, len(heights)):
    height = heights[i]
    max_value = heights[max_index]
    if height > max_value:
        max_index = i
        a.append(1)
    elif height <= heights[i-1] and isMore(height, heights[:max_index]):
        a.append(a[i - 1] - 1)
    else:
        a.append(a[i - 1])

max_zeros = 0
max_index = 0
num_zeros = 0

hold = 0
a.append(1)

# a = [1, 0,0,0,0,0, 1, 0, 1]
# print(a)
# a = a[::-1]

for j in range(1, len(a)):
    i = a[j]
    if i == 1:
        if num_zeros > max_zeros:
            max_zeros = num_zeros
            max_index = hold
        num_zeros = 0
    elif i == 0:
        num_zeros += 1
        if a[j - 1] == 1:
            hold = j - 1
        



print(max_index + 1)