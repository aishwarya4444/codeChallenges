/*
https://codeforces.com/problemset/problem/682/D
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int dp[1001][1001][11][2];
string s, t;
int n, m, k;

int solve(int i, int j, int str, int cont) {
    if(str==k || i==n || j==m) {
        return 0;
    }

    if(dp[i][j][str][cont] != -1) {
        return dp[i][j][str][cont];
    }

    int ans = INT_MIN;

    // whether we wanted to extend string from before or not
    // it cannot be done now
    ans = max(ans, solve(i, j+1, str+cont, 0));
    ans = max(ans, solve(i+1, j, str+cont, 0));

    if(s[i]==t[j]) {
        // place separator
        ans = max(ans, 1+solve(i+1, j+1, str+1, 0));
        // do not place separator
        ans = max(ans, 1+solve(i+1, j+1, str, 1));
    }

    return dp[i][j][str][cont] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));

    cin>>n>>m>>k;
    cin>>s>>t;

    // solve(index of s, index of t, number of strings, is continuous)
    cout<<solve(      0,          0,                 0,             0);

    return 0;
}
