# Using a Python dictionary to act as an adjacency list
graph = {
  '5' : ['3','7'],
  '3' : ['2', '4'],
  '7' : ['8'],
  '2' : [],
  '4' : ['8'],
  '8' : []
}

visited = set() # Set to keep track of visited nodes of graph.

def dfs(visited, graph, node, sfind):  #function for dfs 
    if node not in visited and node != sfind:
        print (node)
        # if node == sfind:
        #     print("Found node to find: ", sfind)
            

        visited.add(node)
        for neighbour in graph[node]:
            dfs(visited, graph, neighbour, sfind    )
    else:
        print(node)

# Driver Code
print("Following is the Depth-First Search")
dfs(visited, graph, '5', '8')