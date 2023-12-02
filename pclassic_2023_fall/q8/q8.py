grid = []

for _ in range(0, 5):
    grid.append([x for x in input()])

l, r = input().split()

s = input()

positions = {

}

for row in range(0, 5):
    for col in range(0, 5):
        item = grid[row][col]
        positions[item] = [row, col] # Y THEN X

print(positions)

lpos = positions[l]
rpos = positions[r]

print(lpos)
print(rpos)

def manhattan_distance(p1, p2):
    return max(abs(p1[0] - p2[0]), abs(p1[1] - p2[1]))

moves = 0

for c in s:
    current_cords = positions[c]
    mdist_for_l = manhattan_distance(lpos, current_cords)
    mdist_for_r = manhattan_distance(lpos, current_cords)

    print("Mdist for l: ", mdist_for_l)
    print("Mdist for r: ", mdist_for_r)

    if mdist_for_r < mdist_for_l:
        rpos = current_cords
    else:
        lpos = current_cords
    moves += min(mdist_for_l, mdist_for_r)
    moves += 1
    # Manhattan distance of both
print("MOVES TAKEN: ", moves)