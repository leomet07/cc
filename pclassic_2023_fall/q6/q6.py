
start =  ord("A")
chars = list(map(str, range(0, 10))) + list(map(chr, list(range(start, start + 26))))

# print(chars)

n = int(input())

s = ""

l = [1]

while True:
    l.append(len(l) * l[-1]) # Effecient factorial
    if l[-1] > n:
        break

l = l[1:len(l) - 1]

# print("List: ", l)

for i in range(len(l) -1, -1, -1):
    times_to_fit = n // l[i] # max times we can fit it
    # print("times to fit: ", times_to_fit)
    # print("Character: ", chars[times_to_fit - 1])
    s = s + chars[times_to_fit]
    n -= l[i] * times_to_fit
    # new_digit_place = len(s) + 1
    # value_of_new_digit = math.factorial(new_digit_place)

    # print(value_of_new_digit)
    # s += chars[new_digit_place - 1]

print(s)


