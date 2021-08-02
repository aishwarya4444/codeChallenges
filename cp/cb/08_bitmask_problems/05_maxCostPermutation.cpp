/*
Given an array A we have to find a permutation with maximum cost where cost of a
permutation P is defined as P[i]*i for all i from 0 to n-1

Input Format
The first line contains an integer N, followed by N numbers in the next line denoting the elements of array A.

Constraints
N<=20
Ai<=20.

Output Format
Output is a single number denoting the maximum cost.

Sample Input
5
1 2 3 4 5

Sample Output
40

Explanation
Max cost can be obtained from permutation
{ 1, 2, 3, 4, 5 }
*/

// greedy and simple approach is to sort and multiply

#include<bits/stdc++.h>
using namespace std;

#define ll  long long

int n;
int a[20];
ll dp[1<<20];

ll solve(int mask) {
    if(mask == (1<<n)-1) {
        return 0;
    }
    if(dp[mask] != -1) {
        return dp[mask];
    }

    ll ans = INT_MIN;

    for(int j=0; j<n; j++) {
        if(mask & (1<<j)) continue;
        ans = max(ans, j*a[j] + solve(mask | (1<<j)));
    }

    return dp[mask] = ans;
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++) {
        cin>>a[i];
    }

    memset(dp, -1, sizeof dp);

    cout<<solve(0);

    return 0;
}
