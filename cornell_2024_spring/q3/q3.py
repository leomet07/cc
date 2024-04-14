n = int(input())

s = 0
for i in range(n):
    nums = list(map(int, input().split()))
    for index in range(len(nums)):
        if index == i:
            continue

        s += nums[index]

print(s)
