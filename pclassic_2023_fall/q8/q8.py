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

# print(positions)

lpos = positions[l]
rpos = positions[r]

# print(lpos)
# print(rpos)

def manhattan_distance(p1, p2):
    return max(abs(p1[0] - p2[0]), abs(p1[1] - p2[1]))


def solve(i):
    global lpos
    global rpos
    if i == len(s):
        return 0
    current_cords = positions[s[i]]
    mdist_for_l = manhattan_distance(lpos, current_cords)
    tmp = lpos.copy()
    lpos = current_cords
    left_dist = solve(i + 1) + mdist_for_l
    lpos = tmp

    mdist_for_r = manhattan_distance(rpos, current_cords)
    tmp = rpos.copy()
    rpos = current_cords
    right_dist = solve(i + 1) + mdist_for_r
    rpos = tmp




    return  min(left_dist, right_dist) + 1
    # Manhattan distance of both
moves = solve(0)

print(moves)
# print("MOVES TAKEN: ", moves)