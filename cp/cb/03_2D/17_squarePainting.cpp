/*
https://codeforces.com/problemset/problem/1200/D

Apaar likes to paint his heart out. He made a famous painting software letspaint.
The working screen of letspaint is square-shaped consisting of n rows and n columns of square cells.
The rows are numbered from 1 to n, from top to bottom, and the columns are numbered from 1 to n, from left to right.
The position of a cell at row r and column c is represented as (r,c).
There are only two colors for the cells in letspaint — black and white.

There is a tool named eraser in letspaint. The eraser has an integer size k (1≤k≤n).
To use the eraser, Apaar needs to click on a cell (i,j) where 1≤i,j≤n−k+1.
When a cell (i,j) is clicked, all of the cells (i′,j′) where i≤i′≤i+k−1 and j≤j′≤j+k−1 become white.
In other words, a square with side equal to k cells and top left corner at (i,j) is colored white.

A white line is a row or a column without any black cells.

Apaar has worked with letspaint for some time, so some of the cells (possibly zero or all) are currently black.
He wants to know the maximum number of white lines after using the eraser exactly once.
Help him find the answer to his question.

Input Format
The first line contains two integers n and k (1≤k≤n≤2000) — the number of rows and columns, and the size of the eraser.

The next n lines contain n characters each without spaces.
The j-th character in the i-th line represents the cell at (i,j).
Each character is given as either 'B' representing a black cell, or 'W' representing a white cell.

Constraints
1 ≤ k ≤ n ≤ 2000

Output Format
Print one integer: the maximum number of white lines after using the eraser exactly once.

Sample Input
5 3
BWBBB
BWBBB
BBBBB
BBBBB
WBBBW

Sample Output
2

Explanation
In the example, both the 2-nd column and 5-th row become white lines by clicking the cell (3,2).
*/

