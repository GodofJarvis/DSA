# Shortest path in a directed graph with weighted edges

Begin with the starting node recurse till reaching the destination node and set cost as 0 in dest node. Then while returning set cost of each node as (a--'>'b)edge weight + cost of b node.


Finally cost matrix will have minimum cost between any source and all destination.
