# Shortest path in a matrix

Source is (0,0) and the destination is marked as 9 (the location of dest cell is not provided). The walls are marked as 1.

Navigate through matrix only by UP, DOWN, LEFT & RIGHT.

### Input cells:

|Maze |  0  |  1  |  2  |  3  |  4  |  7  |  5  |  8  |  9  |
|-----|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|**0**|  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |
|**1**|  0  |  0  |  0  |  1  |  1  |  0  |  0  |  0  |  0  |
|**2**|  1  |  0  |  0  |  1  |  1  |  0  |  0  |  0  |  0  |
|**4**|  0  |  0  |  0  |  9  |  0  |  0  |  0  |  0  |  0  |
|**5**|  0  |  0  |  1  |  0  |  0  |  1  |  0  |  0  |  0  |
|**7**|  1  |  0  |  0  |  0  |  0  |  1  |  0  |  0  |  0  |
|**8**|  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |


### OUTPUT:

Shortest path between S(0,0) to D(9)

Reached D with distance: 7

|Cost |  0  |  1  |  2  |  3  |  4  |  7  |  5  |  8  |  9  |
|-----|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|**0**|  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  0  |
|**1**|  2  |  3  |  4  |  0  |  0  |  7  |  8  |  0  |  0  |
|**2**|  0  |  4  |  5  |  0  |  0  |  8  |  0  |  0  |  0  |
|**4**|  6  |  5  |  6  |  7  |  0  |  0  |  0  |  0  |  0  |
|**5**|  7  |  6  |  0  |  0  |  0  |  1  |  0  |  0  |  0  |
|**7**|  0  |  7  |  0  |  0  |  0  |  1  |  0  |  0  |  0  |
|**8**|  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |
