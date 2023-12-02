n = int(input())

for i in range(n):
    nums = list(map(int, input().split()))
    a = nums[0]
    b = nums[1]

    if len(str(a + b)) > len(str(a)):
        print("YES")
    else:
        print("NO")