# Shortest path in a directed graph with weighted edges

Begin with the starting node recurse till reaching the destination node and set cost as 0 in dest node. Then while returning set cost of each node as (a-->b)edge weight + cost of b node.


Finally cost matrix will have minimum cost between any source and all destination.

### Input

Directed graph provided in code

![Directed graph provided in code](https://user-images.githubusercontent.com/16428435/76882251-65c9c700-68a0-11ea-8ad6-06e8145eea4c.PNG)
