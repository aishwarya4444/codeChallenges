/*
You are given N stones, labeled from 1 to N. The i-th stone has the weight W[i].
There are M colors, labeled by integers from 1 to M.
The i-th stone has the color C[i] (of course, an integer between 1 to M, inclusive).
You want to fill a Knapsack with these stones. The Knapsack can hold a total weight of X.
You want to select exactly M stones; one of each color.
The sum of the weights of the stones must not exceed X.
Since you paid a premium for a Knapsack with capacity X (as opposed to a Knapsack with a lower capacity),
you want to fill the Knapsack as much as possible.
Write a program that takes all the above values as input and calculates the best way to fill the Knapsack - that is,
the way that minimizes the unused capacity.
Output this unused capacity. See the explanation of the sample test cases for clarity.

Input Format
The first line contains three integers, N, M and X, separated by single space.
The next line contains N integers, W[1], W[2], W[3] … W[N], separated by single space.
The next line contains N integers C[1], C[2], C[3] … C[N], separated by single space.

Constraints
1 ≤ M ≤ 100
M ≤ N ≤ 100
1 ≤ W[i] ≤ 100
1 ≤ C[i] ≤ M
1 ≤ X ≤ 10000

Output Format
An optimal way of filling the Knapsack minimizes unused capacity.
There may be several optimal ways of filling the Knapsack.
Output the unused capacity of the Knapsack (a single integer on a line by itself) for an optimal way.
If there is no way to fill the Knapsack, output -1.

Sample Input
9 3 10
1 3 5 1 3 5 1 3 5
1 1 1 2 2 2 3 3 3

Sample Output
1

Explanation
You cannot select stones such that the knapsack is completely full.
You can select stones {1, 4, 9}, such that the unused capacity is 10-1-1-5 = 3.
But there is a better way. Select stones {2, 5, 8}. The unused capacity is 10-3-3-3 = 1.
This is the optimal way. There is another way that is optimal.
Select stones {1, 5, 9}. The unused capacity is 10-1-3-5 = 1.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
int N, M, X;
int w[101];
int c[101];
unordered_map<int, unordered_set<int> > bag;
int dp[101][10001];

int solve(int color, int cap) {
    if(cap<0) {
        return INT_MIN;
    }
    if(color>M) {
        return 0;
    }

    if(dp[color][cap] != -1) {
        return dp[color][cap];
    }

    int res=INT_MIN, sum;
    for(int wt: bag[color]) {
        sum = solve(color+1, cap-wt);
        if(sum != INT_MIN) {
            sum += wt;
        }
        res = max(res, sum);
    }

    return dp[color][cap] = res;
}

int main() {
    cin>>N>>M>>X;

    for(int i=0; i<N; i++) {
        cin>>w[i];
    }

    for(int i=0; i<N; i++) {
        cin>>c[i];
        bag[c[i]].insert(w[i]);
    }

    memset(dp, -1, sizeof dp);

    int maxWt = solve(1, X);

    if(maxWt != INT_MIN) {
        cout<<X-maxWt;
    } else {
        cout<<-1;
    }

    return 0;
}
