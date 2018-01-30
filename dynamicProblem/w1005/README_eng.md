# problem
- There are orders to build buildings. It is like a prerequisite in a school, thus, we have to follow those orders
  until a specific buliding.
- For example, our goal is D. Before that, we would start to build in A building.

  * A -> B
  * A -> C
  * B -> D
  * C -> D

  In this situation, the prerequisites of D are B, C. Besides the prerequisites of B, c are A. Like this way, we will
  start from the start and reach D bulding. The point is to calculate its cost until D. If the level of prerequisites was same, we would remember and calculate the maximum of the prerequisites.

# condition
- 1 ¡Â N ¡Â 1000, 1 ¡Â K ¡Â 100000 , 1¡Â X,Y,W ¡Â N, 0 ¡Â D ¡Â 100000

  *  N : the number of buildings, K : the number of order[X -> Y],
  *  X, Y : the specific buildings, D : the cost of [X -> Y]

# input
2               //T : the number of testcases
4 4             // N, K
10 1 100 10     //the cost of cost[i]
1 2
1 3
2 4
3 4
4               //W : the goal of a testcase;
8 8
10 20 1 5 8 7 1 43
1 2
1 3
2 4
2 5
3 6
5 7
6 7
7 8
7

# output
120
39

//We have to print the cost util reaching goals about each testcases.
