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
    elif heights[i-1] == max_value and isMore(height, heights[:max_index]):
        a.append(0)
    elif height < heights[i-1]:
        a.append(-1)
    else:
        a.append(0)

max_zeros = 0
max_index = 0
num_zeros = 0

hold = 0
a.append(1)

# a = [1, 0,0,0,0,0, 1, 0, 1]
print(a)
# a = a[::-1]

neg = 0

for j in range(1, len(a)):
    i = a[j]
    if i == 1:
        if max_zeros == 0 and j == len(a)-1 and neg > 0:
            max_index = len(a) - 2
        elif num_zeros > max_zeros:
            max_index = hold
            num_zeros = 0
        neg = 0
    elif i == 0:
        num_zeros += 1
        if a[j - 1] == 1:
            hold = j - 1
    elif i == -1:
        neg += 1
        



print(max_index + 1)