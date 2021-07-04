/*
You've heard of 0-1 knapsack. Below is the problem statement for the same.

Given weights and values of n items, put these items in a knapsack of capacity cap to get the maximum total value in the knapsack.
In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively.
Also given an integer cap which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to cap.
You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
There is a little twist for 0-N knapsack. You can pick an element more than once.
Now you have to find maximum value multi subset of val[] such that sum of the weights of this subset is smaller than or equal to cap.

Note: Maximum value subset means the sunset with maximum sum of all the values in subset.

Input Format
The first line contains two integers, representing n(size of val[]) and cap respectively.
The subsequent line contains n integers representing the wt[] array.
The next line, again, contains n integers representing the val[] array.

Constraints
1 <= n,cap <= 1000
1 <= wt[i] <= cap
1 <= val[i] <= 100000

Output Format
Print a single integer, the answer to the problem.

Sample Input
5 11
3 2 4 5 1
4 3 5 6 1

Sample Output
16

Explanation
We take second item 4 times and fifth item one time to make the total values 16.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
int dp[1001][1001];
int wt[1001];
int val[1001];

int main() {
    int n, cap;
    int cost0, cost1;

    cin>>n>>cap;

    for(int i=0; i<n; i++) {
        cin>>wt[i];
    }

    for(int i=0; i<n; i++) {
        cin>>val[i];
    }

    for(int i=0; i<n; i++) {
        for(int c=0; c<=cap; c++) {
            cost0 = 0;
            cost1 = 0;
            if(i>0) {
                cost0 = dp[i-1][c];
            }
            if(c>=wt[i]) {
                cost1 = val[i]+dp[i][c-wt[i]];
            }
            dp[i][c] = max(cost0, cost1);
        }
    }

    cout<<dp[n-1][cap];

    return 0;
}
