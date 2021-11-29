

graph = {
    'A': ['B', 'C', "D"],
    'B': ['E', "F"],
    'C': ['G', "I"],
    'D': ["I"],
    'E': [],
    "F": [],
    'G': [],
    "I": []
}
 
def bfs(visit_complete, graph, current_node, sfind):
    visit_complete.append(current_node)
    queue = []
    queue.append(current_node)
 
    while queue and current_node != sfind:
        s = queue.pop(0)
        print(s)

        if (s == sfind):
            print("Found in loop: ", s)

		

        for neighbour in graph[s]:
            if neighbour not in visit_complete:
                visit_complete.append(neighbour)
                queue.append(neighbour)

    if current_node == sfind:
        print("Found: ", current_node)
 
bfs([], graph, 'A', "E")
