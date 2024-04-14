n, r, q = map(int, input().split())

moves = []

isSwapped = [False] * n

for i in range(r):
    move = list(map(int, input().split()))
    for j in range(move[0] - 1, move[1] - 1):
        isSwapped[j] = True
    moves.append(move)

rmoves = moves[::-1]

# print(moves)
for i in range(q):
    x = int(input())
    if not isSwapped[x - 1]:
        print(x)
        continue

    for move in rmoves:
        if x < move[0] or x > move[1]:
            continue
        else:
            diff = x - move[0]
            x = move[1] - (diff)
    print(x)

    # question
