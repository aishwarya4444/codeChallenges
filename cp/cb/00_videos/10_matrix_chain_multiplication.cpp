/*
https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
https://leetcode.com/problems/burst-balloons/
https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int dp[100][100];

int solve(int *a, int l, int r) {
    if(l==r) {
        return 0;
    }

    if(dp[l][r]!=-1) {
        return dp[l][r];
    }

    int cost = INT_MAX;
    for(int i=l; i<r; i++) {
        cost = min(cost, solve(a, l, i) + solve(a, i+1, r) + a[l-1]*a[i]*a[r]);
    }

    return dp[l][r] = cost;

}

int main() {
    int arr[] = { 1, 2, 3, 4};
    int n = 3;

    memset(dp, -1, sizeof(dp));

    cout<<solve(arr, 1, n);

    return 0;

}
