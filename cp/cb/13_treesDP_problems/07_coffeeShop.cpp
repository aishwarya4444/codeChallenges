/*
Two friends Alice and Bob decided to start coffee shops in TreeLand.
TreeLand is a country consisting of N cities arranged in the form of a Tree.
(Undirected Connected Acyclic Graph).
Both friends wanted build their shops at same place but they were told that to avoid competition,
the shops must be exactly K units away from each other.
(The distance between two cities is the number of edges in the path between the two cities)
Now Alice and Bob wonders, what can be the possible number of pairs of cities
so that distance between them is exactly K units. Can you help them?

Input Format
First line of the input contains two integer numbers representing
the number of cities N present in TreeLand and required distance K.
Next N-1 lines contains two integers A and B,
representing that city A and city B are connected by a direct edge.

Constraints
0<N<=100000
0<K<=10

Output Format
Output a single integer representing the number of pairs of cities having distance exactly K.

Sample Input
6 2
1 2
1 3
3 4
3 5
4 6

Sample Output
5

Explanation
(The required pairs will be {1,4} , {2,3} , {3,6} , {4,5} , {1,5}.)
*/
