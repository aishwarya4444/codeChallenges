/*
https://www.spoj.com/problems/MIXTURES/
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int a[101];
int sum[101];
int dp[101][101];

int csum(int l, int r) {
    return (sum[r]-sum[l-1]+100)%100;
}

int solve(int i, int j) {
    if(i>=j) {
        return 0;
    }

    if(dp[i][j]!=-1) {
        return dp[i][j];
    }

    dp[i][j] = INT_MAX;

    for(int k=i; k<=j; k++) {
        dp[i][j] = min(dp[i][j], solve(i, k) + solve(k+1, j) + csum(i, k)*csum(k+1, j));
    }

    return dp[i][j];
}

int main() {
    while(cin>>n) {

        memset(dp, -1, sizeof(dp));

        for(int i=1; i<=n; i++) {
            cin>>a[i];
            sum[i] = (a[i]+sum[i-1])%100;
        }

        cout<<solve(1, n)<<endl;
    }

    return 0;

}
