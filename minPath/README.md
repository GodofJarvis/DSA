# Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left (0 x 0) to bottom right (m x n) which minimizes 
the sum of all numbers along its path.You can only move either down or right at any point in time.

### Solution:

The implementation is based on bottom up approach, which helps to calculate minimum cost between all nodes (as source) and destination.

### Sample I/O:

[1,3,1]

[1,5,1]

[4,2,1]

Output: 7

Explanation: 1→3→1→1→1 minimizes the sum.
