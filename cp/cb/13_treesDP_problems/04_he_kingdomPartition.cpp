/*
https://www.hackerearth.com/problem/algorithm/king-of-warland/

Louise is the king of Warland.
Warland is a special kingdom somewhere beyond seven seas.
It consists of N provinces and N-1 roads connecting these provinces.
Roads are such that every two provinces are connected directly or indirectly through a road.
The provinces are numbered as 1,2,3 ……. N.
Louise has two sons Keneth and Benjamin, both his sons possess the potential to become the heir of the throne.
Louise was in dilemma so he asked his ministers to solve this problem.
One of the ministers came up with an idea,
he suggested to distribute some of the provinces to Keneth and some to Benjamin.
Louise wants to stop his sons from fighting,
so he will not allot them neighboring provinces (Neighboring provinces are those directly connected by roads).
Louise will keep one province for himself.

He will allot them provinces in such a way that his province lies
in the path of every two provinces X and Y such that X belongs to Keneth and Y belongs to Benjamin .

Let “a” be the number of provinces given to Keneth and “b” be the number of provinces given to Benjamin.
Then the sum of a and b should be N-1 as the king will have 1 province and a>0 & b>0.
Tell the number of unique pairs (a,b) in which the King can partition his Kingdom.

INPUT FORMAT
First line of the input contains a single integer representing the number of provinces N in the kingdom.
Each of the next N-1 lines contains two integers A and B,
representing that province A and province B are connected via a direct road.

3<=N<=5000
1<=A,B<=N

Output Format
Print number of unique pairs (a,b) ,representing provinces of Keneth and Benjamin.
(a,b) and (b,a) are considered two unique pairs .

Sample Input
6
1 2
1 3
2 4
4 6
3 5

Sample Output
4

Explanation
Max value of a + b is 5.
All possible ways to distribute are :
{6} belong to Keneth and {2,1,3,5} belong to Benjamin which gives (1,4)
{6,4} belong to Keneth and {1,3,5} belong to Benjamin which gives (2,3)
{6,4,2} belong to Keneth and {3,5} belong to Benjamin which gives (3,2)
{6,4,2,1} belong to Keneth and {5} belong to Benjamin which gives (1,4)

Suppose if we distribute like {6,4,3} for Keneth and {2,5} for Benjamin.
We can see that 3 and 5 are neighbors in our kingdom
hence this type of allotment will not work due to conflict between Keneth and Benjamin.
Similarly 2 and 4 are neighbors hence this will also not work .
*/

