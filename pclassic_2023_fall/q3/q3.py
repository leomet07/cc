c = int(input())
input()
nums = list(map(int, input().split()))
input()
c = sum(list(map(int, input().split()))) + c

for i in nums:
    c *= i

print(c)