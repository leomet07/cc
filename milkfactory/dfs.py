# graph = {
#     'A' : ['B','C'],
#     'B' : ['D', 'E'],
#     'C' : ['F'],
#     'D' : [],
#     'E' : ['F'],
#     'F' : [],
#     'G' : []
# }


graph = {
    1 : [2],
    3 : [2]
}
visited = set() # Set to keep track of visited nodes.


##################
# The Algorithm (In Code)

def dfs(visited, graph, node):
    if node not in visited:
        print (node)
        visited.add(node)
        for neighbour in graph[node]:
            dfs(visited, graph, neighbour)
    return visited
            
# Driver Code to test in python yourself.
# Note that when calling this, you need to
# call the starting node. In this case it is 'A'.
visited = dfs(visited, graph, 2)
print(visited)