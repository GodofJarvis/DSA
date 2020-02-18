# Graph traversal

BFS: Start with first node and put all linked nodes to the current node in a queue. 
Repeat by taking next node from the queue till all nodes are visited / queue is empty.

DFS: Print the first node and get next link of current node and recurse till there is
no unvisited connected node exist.

![Sample graph connection](https://user-images.githubusercontent.com/16428435/74755734-9581b100-5299-11ea-8362-a47615de22c2.PNG)

### Output:

Graph Traversal

Number of nodes: 9

Number of edges: 8

DFS: 1 2 5 6 3 4 8 7 9

BFS: 1 2 3 5 4 7 6 8 9
