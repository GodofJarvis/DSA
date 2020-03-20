# Rotten oranges

A basket containing n oranges (represented by 1/2), each box in the basket can have one of three values:

* 0 - empty cell
* 1 - fresh orange
* 2 - rotten orange

Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Calculate the minimum number of minutes that must elapse until no cell has a fresh orange (or) there will be unreachable fresh oranges.

### Sample input & solution:

Basket contents:

0 0 0 1 1 1

0 0 2 2 0 1

0 0 0 0 1 1

0 0 0 0 0 1

0 0 0 0 1 2

0 0 0 0 0 0

Minutes elapsed: 3
