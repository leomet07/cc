n, r, q = map(int, input().split())

moves = []

for i in range(r):
    moves.append(list(map(int, input().split())))

rmoves = moves[::-1]

# print(moves)
for i in range(q):
    x = int(input())
    for move in rmoves:
        if x < move[0] or x > move[1]:
            continue
        else:
            diff = x - move[0]
            x = move[1] - (diff)
    print(x)

    # question
