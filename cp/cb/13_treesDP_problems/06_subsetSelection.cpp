/*
You are given a Tree with N vertices.
(A Tree is a connected graph without cycles.)
Each vertex of the Tree have some positive integral value associated with it.
Find a subset of vertices which satisfies the following two conditions:
  [1] The sum of values on these vertices is maximum possible.
  [2] For any two vertices in the set,the distance between them is always greater than or equal to 2.
      (Distance between two vertices a and b is the number of edges present in the path from a to b.)

Input Format
First line of the input contains the number of nodes N present in the tree.
Second line contains N integers representing the value of each node.
Next N-1 lines contains two integers A and B ,representing a node between vertex A and vertex B.

Constraints
0<n<=100000
1<=Ai<=100000 (Value of ith node)

Output Format
Output a single integer representing the maximum sum of values on vertices present in set.
(Note: You do not have to maximize the number of elements in the set.You only have to maximize the sum of values associated with the vertices in the set.)

Sample Input
6
2 5 3 7 4 8
1 2
1 3
3 4
3 5
4 6

Sample Output
17

Explanation
(The required set will be {2,5,6}.
For any two elements, their distance d>=2 and sum of their values is maximum.)
*/
