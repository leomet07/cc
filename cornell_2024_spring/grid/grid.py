def count_codes(word :str):
    arrrrr = [0, 0, 0, 0]
    for letter in word:
        if letter == "c":
            arrrrr[0] += 1
        if letter == "o":
            arrrrr[1] += arrrrr[0]
        if letter == "d":
            arrrrr[2] += arrrrr[1]
        if letter == "e":
            arrrrr[3] += arrrrr[2]
    return arrrrr[3]

# print(count_codes("cocodee"))
# print(count_codes("code"))
# print(count_codes("codee"))
# print(count_codes("codecode"))
# print(count_codes())

n, m, x, y = map(int, input().split())

# print(n, m, x, y) 

board = []
for i in range(n):
    board.append(input())

for i in range(n - x + 1):
    for j in range(m - y + 1):
        combined = ""
        for h in range(i, i + x):
            combined += board[h][j: j+y]
        print(count_codes(combined), end="")
        # print(combined, end="")
        if j != m - y:
            print(' ', end="")
    print()