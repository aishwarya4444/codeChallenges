/*
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n.
Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Input Format
n, size of array Ai, value of array elements

Constraints
1<= n <= 10^5 1<= Ai <=10^5

Output Format
Maximum value obtainable by cutting up the rod and selling the pieces.

Sample Input
5
1 2 3 4 5
Sample Output
5
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[100001];
ll dp[100001];
// int N;

ll solve(int n) {
    if(n==0) return 0;

    if(dp[n]) {
        return dp[n];
    }

    ll cost = 0;

    for(int i=1; i<=n; i++) {
        // if(n>=i) {
            cost = max(cost, a[i]+solve(n-i));
        // }
    }

    return dp[n] = cost;
}

int main() {
    int n;

    cin>>n;
    // N = n;

    for(int i=1; i<=n; i++) {
        cin>>a[i];
    }

    cout<<solve(n);
}
